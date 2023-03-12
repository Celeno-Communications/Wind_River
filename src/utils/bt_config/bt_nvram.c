
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "bt_nvram.inc"

#define MAX_OUTDATA_SIZE 1024

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

static uint8_t outData[MAX_OUTDATA_SIZE];

enum {
	VALUE_TYPE_NUMBER = 1,
	VALUE_TYPE_STRING,
	VALUE_TYPE_MAC
};

static const struct nvram_element * (* getElement)(const char *name) = nvram_getElement;

struct csv_element_s {
	struct nvram_element nv;
	struct csv_element_s *next;
	char name[0];
};

static struct csv_element_s * csv_hash[ARRAY_SIZE(nvram_hash)];
static int csv_bin_offset = sizeof(nvram_value);

static const struct nvram_element * csv_getElement(const char *name)
{
	unsigned short index;
	struct csv_element_s *el;

	index = nvram_getHash(name);
	el = csv_hash[index];

	while (el) {

		if (!strcmp(name, el->nv.name))
			return &el->nv;

		el = el->next;
	}

	return NULL;
}

static void csv_init(void)
{
	memset(&csv_hash[0], 0, sizeof(csv_hash));
	csv_bin_offset = 0;
}

static void csv_purifyParamName(char *strParmName)
{
	char *strModified = strParmName;
	int skip = 0;

	for (; *strParmName; strParmName++) {

		if (skip) {

			if (*strParmName == ']')
				skip = 0;
		} else if (*strParmName == '[') {

			skip = 1;
		} else if (*strParmName == ']') {

			*strModified = '_';
			strModified++;
		} else if (*strParmName == '.') {

			*strModified = '_';
			strModified++;
		} else {

			*strModified = *strParmName;
			strModified++;
		}
	}

	*strModified = 0;
}

static void csv_applyHexValue(uint8_t *outData, int length, const char *strValue)
{
	uint8_t value;
	outData += (length - 1);

	while (length) {

		if ((strValue[0] >= '0') && (strValue[0] <= '9'))
			value = strValue[0] - '0';
		else if ((strValue[0] >= 'a') && (strValue[0] <= 'f'))
			value = strValue[0] - 'a' + 10;
		else if ((strValue[0] >= 'A') && (strValue[0] <= 'F'))
			value = strValue[0] - 'A' + 10;
		else
			break;

		value <<= 4;

		if ((strValue[1] >= '0') && (strValue[1] <= '9'))
			value |= strValue[1] - '0';
		else if ((strValue[1] >= 'a') && (strValue[1] <= 'f'))
			value |= strValue[1] - 'a' + 10;
		else if ((strValue[1] >= 'A') && (strValue[1] <= 'F'))
			value |= strValue[1] - 'A' + 10;
		else
			break;

		*outData = value;
		outData--;
		length--;
		strValue += 2;
	}

	while (length) {

		*outData = 0;
		outData--;
		length--;
	}
}

static void csv_processLine(char *line)
{
	unsigned short index;
	char *strParmName;
	char *strLength;
	char *strValue;
	int iLength;
	struct csv_element_s *el;
	int nameLen;

	strParmName = line;
	line = strchr(line, ',');
	if (!line)
		return;
	*line = 0;
	line++;

	strLength = line;
	line = strchr(line, ',');
	if (!line)
		return;
	*line = 0;
	line++;

	strValue = line;
	line = strchr(line, ',');
	if (!line)
		return;
	*line = 0;

	iLength = strtol(strLength, NULL, 10);

	csv_purifyParamName(strParmName);
	csv_applyHexValue(&outData[csv_bin_offset], iLength, strValue);
	index = nvram_getHash(strParmName);

	nameLen = strlen(strParmName) + 1;

	el = (struct csv_element_s *)malloc(sizeof(*el) + nameLen);
	el->nv.name = &el->name[0];
	el->nv.offset = csv_bin_offset;
	el->nv.length = iLength;
	memcpy(&el->name[0], strParmName, nameLen);
	el->next = csv_hash[index];
	csv_hash[index] = el;

	csv_bin_offset += iLength;
	getElement = csv_getElement;
}

void setupValue(unsigned char *buffer, int length, char *value)
{
	char endchar = '\n';
	int vtype = VALUE_TYPE_STRING;
	int num;

	memset(buffer, 0, length);

	if ((*value == '"') || (*value == '\'')) {

		vtype = VALUE_TYPE_STRING;
		endchar = *value;
		value++;
	} else if (strchr(value, ':')) {

		vtype = VALUE_TYPE_MAC;
		endchar = ':';
	} else if (strchr(value, '-')) {

		vtype = VALUE_TYPE_MAC;
		endchar = '-';
	} else if ((*value <= '9') && (*value >= '0')) {

		vtype = VALUE_TYPE_NUMBER;
	} else if (*value == '-') {

		vtype = VALUE_TYPE_NUMBER;
	}

	switch (vtype) {

	case VALUE_TYPE_NUMBER:
		num = strtol(value, NULL, 0);

		while (length) {

			*buffer = num;
			buffer++;
			num >>= 8;
			length--;
		}
		break;

	case VALUE_TYPE_STRING:
		while (length) {

			if (*value == endchar)
				break;
			*buffer = *value;
			buffer++;
			value++;
			length--;
		}

		while (length) {

			*buffer = 0;
			buffer++;
			length--;
		}
		break;

	case VALUE_TYPE_MAC:
		while (length) {

			num = strtol(value, &value, 16);
			*buffer = num;
			buffer++;
			length--;

			if (*value != endchar)
				break;

			value++;
		}

		while (length) {

			*buffer = 0;
			buffer++;
			length--;
		}
		break;
	}
}

int processLine(char *line)
{
	const struct nvram_element *el;
	char *eqSign;

	// Skip comments
	if (*line == '#')
		return 0;

	eqSign = strchr(line, '=');
	if (!eqSign)
		return -1;

	*eqSign = 0;
	eqSign++;

	el = getElement(line);
	if (el) {

		setupValue(&outData[el->offset], el->length, eqSign);
	} else {

		printf("Warning: parameter %s is not found\n", line);
		return -2;
	}

	return 0;
}

static char buf[1024];

int main(int argc, char *argv[])
{
	FILE *fileInput;
	FILE *fileOutput;

	if (argc < 3) {

		printf("Usage: %s <infile.txt> <outfile.bin> [<bt_nvram.csv>]\n", argv[0]);
		return 1;
	}

	if (argc == 4) {

		fileInput = fopen(argv[3], "r");
		if (!fileInput) {

			printf("Can't open file %s for read\n", argv[3]);
			memcpy(outData, nvram_value, sizeof(nvram_value));
		} else {

			csv_init();

			while (fgets(&buf[0], sizeof(buf), fileInput))
				csv_processLine(buf);

			if (!ferror(fileInput))
				csv_processLine(buf);

			fclose(fileInput);
		}
	} else {

		memcpy(outData, nvram_value, sizeof(nvram_value));
	}

	fileInput = fopen(argv[1], "r");
	if (!fileInput) {

		printf("Can't open file %s for read\n", argv[1]);
	} else {

		while (fgets(&buf[0], sizeof(buf), fileInput))
			processLine(buf);

		if (!ferror(fileInput))
			processLine(buf);

		fclose(fileInput);
	}

	fileOutput = fopen(argv[2], "w");
	if (!fileOutput) {

		printf("Can't open file %s for write\n", argv[2]);
		return 3;
	}
	if (fwrite(outData, 1, csv_bin_offset, fileOutput) != csv_bin_offset) {

		printf("Error writing %d bytes to file %s\n", (int)csv_bin_offset, argv[2]);
	}
	fclose(fileOutput);

	return 0;
}

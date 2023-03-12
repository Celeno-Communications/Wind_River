#ifndef __VENDOR_CMD_H
#define __VENDOR_CMD_H

int cl_msg_recv(struct nl_msg *msg, void **pdata, uint16_t *plen);

#define MY_FATAL(err) do { fprintf(stderr, "Error at line %d, func %s [Error: %s]\n", \
  __LINE__, __func__, err); exit(1); } while(0)
#define VALIDATE_IN_RANGE(val, min, max) do{\
	if((val) < (min) || (val) > (max)) \
	MY_FATAL(#val" is out of range");\
	}while(0)

long parse_long(char ***pargv, int *pargc);

#define PARSE_INT_VALIDATE_IN_RANGE(_res, _pargv, _pargc, _low, _high) \
	do{ \
		long tmp = 0;\
		tmp = parse_long((_pargv), (_pargc));\
		VALIDATE_IN_RANGE(tmp, (_low), (_high));\
		_res = tmp;}\
	while(0)

#define PARSE_U8(_res, _pargv, _pargc) \
	PARSE_INT_VALIDATE_IN_RANGE(_res, (_pargv), (_pargc), 0, 255)

#define PARSE_S8(_res, _pargv, _pargc) \
	PARSE_INT_VALIDATE_IN_RANGE(_res, (_pargv), (_pargc), -128, 127)

#define PARSE_U16(_res, _pargv, _pargc) \
	PARSE_INT_VALIDATE_IN_RANGE(_res, (_pargv), (_pargc), 0, 65535)

#define PARSE_U32(_res, _pargv, _pargc) \
	PARSE_INT_VALIDATE_IN_RANGE(_res, (_pargv), (_pargc), 0, 0xffffffff)

#endif // __VENDOR_CMD_H

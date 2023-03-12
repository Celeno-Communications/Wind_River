
import re

class Converter(object):
  def __init__(self):
    pass

  def doConvert(self):
    handleCsv = open("bt_nvram.csv", "r")
    handleInc = open("bt_nvram.inc", "w")
    offset = 0
    itemIndex = 0
    alldata = []

    hashsize = 64
    hashtab = []
    for i in range(0, hashsize):
      hashtab.append(0)

    print ("""
/* This file was created automatically by the conv_nvram_csv2c.py script
 * Please don't modify the contents of this file manually */
struct nvram_element {
  const char * name;
  short offset;
  short length;
  short next;
};
""", file=handleInc)
    print ("const static struct nvram_element nvrams[] = {", file=handleInc)

    for line in handleCsv:
      m = re.search(r"^([a-zA-Z0-9_.\[\]]+),([0-9]+),([0-9a-fA-F]+),", line)
      if m:
        name = re.sub(r"\[[0-9]+\]", "", m.group(1))
        name = re.sub(r"[\.\[\]]", "_", name)
        length = int(m.group(2), 10)
        valueRev = m.group(3)
        value = []

        itemIndex += 1

        for i in range(0, len(valueRev), 2):
          value.insert(0, int(valueRev[i : i + 2], 16))
        if (len(value) >= length):
          alldata.extend(value[:length])
        else:
          alldata.extend(value)
          alldata.extend([0 for i in range(length - len(value))])

        hashval = 0
        for i in range(0, len(name)):
          hashval = (hashval * 31 + ord(name[i])) & 0xffff

        hashval = hashval & (hashsize - 1)
        hashnext = hashtab[hashval]
        hashtab[hashval] = itemIndex

        print("  {\"%s\", 0x%03x, %d, %d}," % (name, offset, length, hashnext), file=handleInc)

        offset += length

    print ("};", file=handleInc)
    print ("const static unsigned char nvram_value[%d] = {" % len(alldata), file=handleInc)

    valuestr = ""
    for i in range(len(alldata)):
      if (i & 7) == 0:
        valuestr = "/* %03x: */  0x%02x" % (i, alldata[i])
      elif (i & 7) == 7:
        print ("%s,0x%02x," % (valuestr, alldata[i]), file=handleInc)
        valuestr = ""
      else:
        valuestr = "%s,0x%02x" % (valuestr, alldata[i])
    if (len(valuestr)):
      print (valuestr, file=handleInc)

    print ("};", file=handleInc)
    print ("const static short nvram_hash[%d] = {" % hashsize, file=handleInc)
    valuestr = ""
    for i in range(len(hashtab)):
      if (i & 7) == 0:
        valuestr = "  %3d" % hashtab[i]
      elif (i & 7) == 7:
        print ("%s,%3d," % (valuestr, hashtab[i]), file=handleInc)
        valuestr = ""
      else:
        valuestr = "%s,%3d" % (valuestr, hashtab[i])
    if (len(valuestr)):
      print (valuestr, file=handleInc)
    print ("};", file=handleInc)
    print ("""
static int nvram_getHash(const char * name) {
  unsigned short hashval = 0;
  for (; *name; name++)
    hashval = hashval * 31 + *name;
  return hashval & (sizeof(nvram_hash) / sizeof(nvram_hash[0]) - 1);
}

static const struct nvram_element * nvram_getElement(const char * name) {
  unsigned short index;
  index = nvram_getHash(name);
  index = nvram_hash[index];
  while (index) {
    if (!strcmp(name, nvrams[index - 1].name))
      return &nvrams[index - 1];
    index = nvrams[index - 1].next;
  }
  return NULL;
}""", file=handleInc)

    handleInc.close()
    handleCsv.close()

c = Converter()
c.doConvert()

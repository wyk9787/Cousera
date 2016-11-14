fname = raw_input("Enter file name: ")
fh = open(fname)
lst = list()
for line in fh:
  line=line.rstrip()
  a=line.split()
  for b in a:
    if not b in lst:
      lst.append(b)
lst.sort()
print lst
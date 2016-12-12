fname = raw_input("Enter file name: ")
if len(fname) < 1 : fname = "mbox-short.txt"
fh = open(fname)
count = 0
a=list()
for lines in fh:
  if lines.startswith("From "):
    a=lines.split()
    count= count+1
    print a[1]

print "There were", count, "lines in the file with From as the first word"

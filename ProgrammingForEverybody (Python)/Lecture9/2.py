name = raw_input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
a=dict()
handle = open(name)
for lines in handle:
  if lines.startswith("From "):
    lines=lines.split()
    name=lines[1]
    a[name]=a.get(name,0)+1
bigcount=None
bigword=None
for key, value in a.items():
  if bigcount == None or value>bigcount:
    bigword=key
    bigcount=value

print bigword,bigcount
  
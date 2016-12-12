name = raw_input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
handle = open(name)
a=dict()
for lines in handle:
  if lines.startswith("From "):
    lines=lines.split()
    hour=lines[5]
    thehour=hour[:2]
    a[thehour]=a.get(thehour,0)+1
b=a.items()
b.sort()
for c in b: 
  print c[0],c[1]
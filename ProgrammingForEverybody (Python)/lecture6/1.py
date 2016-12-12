# Use the file name mbox-short.txt as the file name
n=0
a=0
fname = raw_input("Enter file name: ")
fh = open(fname)
for line in fh:
    if line.startswith("X-DSPAM-Confidence:") : 
	  q=line
	  z=q.find("0")
	  h=q[z:z+6]
	  h=float(h)
	  a=a+h
	  n=n+1
	  continue
print "Average spam confidence:",a/n

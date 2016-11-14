largest=None
smallest=None

while True:
  try:
    a=raw_input("please input the number ")
    if a== "done":
	  break
    a=float(a)
    if largest is None:
	  largest=a
    elif a> largest:
      largest=a	
    if smallest is None:
	  smallest=a
    elif a< smallest:
	  smallest=a
    
  except:
    print"Invalid input"
  
print "Maximum is",int(largest)
print "Minimum is",int(smallest)
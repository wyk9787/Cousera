x=raw_input("please enter the score:")
try:
  x=float(x)
  if x<0.6:
    print "F"
  elif x<0.7:
    print"D"
  elif x<0.8:
    print "C"
  elif x<0.9:
    print "B"
  else:
    print "A"
except:
  print"please input numeric number"


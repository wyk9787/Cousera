def computepay(h,r):
  if h<=40:
	p=h*r
  else:
    p=40*r+((h-40)*1.5*r)
  return p
try:
  hrs= raw_input("Enter Hours:")
  hrs=float(hrs)
  rate= raw_input("Enter rate:")
  rate=float(rate)
  p=computepay(hrs,rate)
  print "pay",p  
except:
  print"please input right number"

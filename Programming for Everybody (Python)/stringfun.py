#fun
a=raw_input("what do you want to say today?")
count=0
n=1
p=1
q=1
def x():
  try:
    c=int(c)
    q=-1
  except:
    print "please input numeric number"	 
for b in a:
  count= count+1
print count
print "there are",count+1,"words and space in what you just said" 
c=raw_input("Am I right?")
while p>0:
  if c=="yes" or c== "Yes" or c== "Yes.":
    print "You sure?"
    c=raw_input("Try to answer again, you sure?") 
  elif c=="no" or c== "No" or c== "No." :
    while q>0:
      c= raw_input("So how many words and space in the sentence you just said?") 
      print x   
    while n>0:
      if c== int(count):
        n=-1
      else:
        print"You sure you know how to count?"
        c=raw_input("Try again:")
    print"Way to find out!"
    p=-1
  
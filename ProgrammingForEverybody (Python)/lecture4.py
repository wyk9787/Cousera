a=raw_input("input the number")
if a<100:
  a= 126
elif a<150:
  a=128
elif a<200:
  a= 130
else:
  a= 132  
def abc(x):
  if x == 126:
    return "hei"
  elif x == 128:
    return "sjsj", x+3
print abc(a), "bai"

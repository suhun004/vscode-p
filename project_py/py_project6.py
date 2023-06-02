def fact_f(num):
  num2 = 1
  for i in range(1, num + 1):
    num2 *= i
  return num2
print(fact_f(3))

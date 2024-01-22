for i in range (1, 101):
  k = 0
  t = i
  while i != 0:
    j = i % 10
    if j == 3 or j == 6 or j == 9:
      print('짝', end='')
      k = 1
    i = i // 10
  if k == 0:
    print(t)
  else:
    print()
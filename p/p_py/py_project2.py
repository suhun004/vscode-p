import random
com = random.randint(1,100)
num = int(input('1부터 100까지의 수중 하나를 입력하세요(1 ~ 100) : '))
min = 1
max = 100
while num != com:
  if min < num < max:
    if num < com:
      print('up')
      min = num + 1
    elif num > com:
      print('down')
      max = num - 1
  else:
    print('범위에 맞추어 입력하세요')
  num = int(input(f'1부터 100까지의 수중 하나를 입력하세요({min} ~ {max}) : '))
print('정답입니다')
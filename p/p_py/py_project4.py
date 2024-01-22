nums = [123, 433, 134, 934, 734, 374, 234, 412, 642, 854]

def find_max(a: list):
  if a:
    maximum = a[0]
    for i in a:
      if maximum < i:
        maximum = i
    return maximum
  return
print(find_max(nums))
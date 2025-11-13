#criar um array com elementos randômicos
#o conteúdo também é randômico
import random

size_arr = random.randrange(1,15)
arr = []

for _ in range(size_arr):
    arr.append(random.randrange(15))
print(arr)

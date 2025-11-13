
import math

# max() e min()
numeros = [10, 50, 8, 20, 3]
print(f'O maior valor é {max(numeros)}.')
print(f'Já {min(numeros)} é o menor valor')

print(f'''
    Portanto o que temos é...
    {max(numeros)} é o maior..
    e {min(numeros)} é o menor.
     Está claro?
''')

# Outra forma menos moderna
print("Eu sou {} e eu tenho {} anos".format('Uéslei', 36))

# Outra forma mais antiga ainda

print("Meu nome é %s e tenho %d anos" % ('Uéslei', 22))

print(f"A raiz quadrada de 81 é {math.sqrt(81)}.")

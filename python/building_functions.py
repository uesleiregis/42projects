# Aprendendo algumas building funcions

# max() e min()
numeros = [20, 3, 4, 6, 1]
print(f"O valor máximo da lista é {max(numeros)} e o mínimo é {min(numeros)}")

# sorted()
print(f"Se ordenarmos a lista, será assim: {sorted(numeros)}")

nomes = ["Maria", "João", "Ana", "Gustavo"]

print(f"""
Mas, e se quisermos ordenar uma lista de palavras?
Se a lista for: {nomes}.
Depois de ordenarmos teremos: {sorted(nomes)}. 
Gostou?
""")

# map() » aplica uma função a cada item da lista.


def quadrado(x):
    return x * x

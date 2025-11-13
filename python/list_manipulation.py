
# max() e min()

# qual o tipo abaixo?
numeros = [10]

# Exemplos de manipulação de listas

# Exemplo 1: append() e extend()
frutas = ["maçã", "banana"]
frutas.append("laranja")  # Adiciona um elemento ao final
frutas.append("Abacaxi")
print(f"Após append: {frutas}")

frutas.extend(["uva", "morango"])  # Adiciona múltiplos elementos
frutas.extend(["Goiaba", "acerola"])
print(f"Após extend: {frutas}")

# Exemplo 2: insert(), remove() e pop()
numeros = [10, 20, 30, 40, 50]
numeros.insert(0, 5)  # Insere 5 no início (posição 0)
numeros.insert(2, 15)
print(f"Após insert no início e insert pos 2: {numeros}")

numeros.insert(3, 25)  # Insere 25 na posição 3
print(f"Após insert: {numeros}")

numeros.remove(30)  # Remove o primeiro elemento com valor 30
print(f"Após remove: {numeros}")

ultimo = numeros.pop()  # Remove e retorna o último elemento
print(f"Último removido: {ultimo}, lista: {numeros}")

# Exemplo 3: slicing, reverse() e sort()
valores = [5, 2, 8, 1, 9, 3]
print(f"Slice [1:4]: {valores[1:4]}")  # Pega elementos do índice 1 ao 3

valores.reverse()  # Inverte a ordem
print(f"Após reverse: {valores}")

valores.sort()  # Ordena em ordem crescente
print(f"Após sort: {valores}")

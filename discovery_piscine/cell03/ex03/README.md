# Explicacao do subject.
Você vai criar um mini gestor de tarefas local (uma lista de afazeres).
O design não importa, desde que a estrutura abaixo seja respeitada. Foque nas funcionalidades.

A lista de tarefas será representada por uma div com id="ft_list".

Dentro desse bloco ft_list vão ficar todas as tarefas ("TO DO").

Cada tarefa é uma div dentro da div ft_list.

Quando uma tarefa é criada, ela deve ser colocada no topo da lista (primeiro lugar). Você mesmo deve criar esse elemento e colocá-lo no lugar certo usando manipulação do DOM.

Deve existir um botão de criação chamado New.

Quando clicado, ele abre uma janela de texto (use prompt) para o usuário escrever uma nova tarefa.

Se o usuário confirmar e o texto não estiver vazio, a nova tarefa deve aparecer no topo da lista.

Para remover uma tarefa, basta clicar nela.

Ao clicar, deve abrir uma janela de confirmação perguntando se o usuário quer mesmo remover aquela tarefa (sim ou não).

Se confirmar, a tarefa deve desaparecer de verdade do DOM (não pode só ficar escondida via CSS).

Implementação extra: a sua lista de tarefas deve ser salva em cookies.

Se a lista tiver tarefas quando o usuário fechar o navegador, ao abrir de novo a mesma lista deve ser carregada e mostrada em ft_list.

Se o(s) cookie(s) não existir(em), a lista começa vazia.

Resumo ainda mais simples (o que você precisa fazer)
Uma div com id="ft_list" que guarda as tarefas.

Cada tarefa é uma div dentro de ft_list.

Botão New:

Ao clicar, usa prompt para pedir o texto.

Se tiver texto, cria uma nova div de tarefa e coloca no topo de ft_list.

Ao clicar em uma tarefa:

Pergunta com confirm (ou similar) se quer apagar.

Se sim, remove essa div do DOM.

Salvar e carregar a lista usando cookies:

Ao mudar a lista, atualizar o cookie.

Ao carregar a página, ler o cookie e recriar as tarefas dentro de ft_list.
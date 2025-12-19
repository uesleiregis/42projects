


const btn = document.getElementById('btn');

let tasksId = 0;
allTasks = [];

btn.addEventListener('click', () => {

    const taskText = prompt("Descreva a tarefa aqui");
    // console.log(taskText);

    // taskText é NULL quando clica "Cancelar"
    // taskText é "" (string vazia) quando clica "OK" sem digitar nada
    // Precisamos verificar AMBOS os casos!
    if (taskText !== null && taskText !== "") {
        allTasks.push(taskText);

        const newDiv = document.createElement('div');
        newDiv.className = 'chield';
        newDiv.id = `task${tasksId}`;

        const newP = document.createElement('p');
        newP.textContent = taskText;

        salvarCookie(newDiv.id, taskText, 7);

        const newBtn = document.createElement('button');
        newBtn.className = 'btn-chield';
        newBtn.textContent = 'done';
        newBtn.id = `b${tasksId}`;

        // Compondo a div chiel com com os filhos
        newDiv.appendChild(newP);
        newDiv.appendChild(newBtn);

        // Inserindo o elemento newDiv NO INÍCIO da lista
        const list = document.getElementById('ft_list');
        list.prepend(newDiv);  // prepend = adiciona no início

        // Removendo 
        newBtn.addEventListener("click", () => {
            deletarCookie(newDiv.id);
            newBtn.parentElement.remove()
        })


        console.log(document.cookie);
        tasksId++;
    }

});

// Carrega as tarefas salvas quando a página iniciar
carregarTarefasDoCookie();

function salvarCookie(nome, valor, diasParaExpirar) {
    // Calcula a data de expiração
    const dataExpiracao = new Date();
    dataExpiracao.setDate(dataExpiracao.getDate() + diasParaExpirar);

    // Monta o cookie como string
    // encodeURIComponent() garante que caracteres especiais funcionem
    const cookie = `${nome}=${encodeURIComponent(valor)}; expires=${dataExpiracao.toUTCString()}; path=/`;

    // Salva no navegador
    document.cookie = cookie;

    console.log(`✅ Cookie "${nome}" salvo com valor: "${valor}"`);
}
function deletarCookie(nome) {
    // Para deletar, define uma data de expiração no PASSADO
    document.cookie = `${nome}=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/`;
    console.log(`🗑️ Cookie "${nome}" deletado`);
}

// ============================================================
// FUNÇÃO PARA CARREGAR TAREFAS DOS COOKIES AO INICIAR
// ============================================================
function carregarTarefasDoCookie() {
    // Se não houver cookies, sai da função
    if (document.cookie === "") {
        console.log("❌ Nenhum cookie encontrado");
        return;
    }

    // document.cookie retorna: "task0=Estudar; task1=Treinar; task2=Ler"
    const cookies = document.cookie.split('; ');

    const list = document.getElementById('ft_list');

    // Filtra apenas cookies de tarefas e ordena pelo ID (maior primeiro)
    const tarefas = cookies
        .filter(cookie => cookie.startsWith('task'))
        .sort((a, b) => {
            const idA = parseInt(a.split('=')[0].replace('task', ''));
            const idB = parseInt(b.split('=')[0].replace('task', ''));
            return idB - idA; // Ordem decrescente (mais recente primeiro)
        });

    tarefas.forEach(cookie => {
        const [id, valor] = cookie.split('=');

        const taskText = decodeURIComponent(valor);

        // Extrai o número do ID (ex: "task5" → 5)
        const numId = parseInt(id.replace('task', ''));

        // Atualiza tasksId para evitar IDs duplicados
        if (numId >= tasksId) {
            tasksId = numId + 1;
        }

        // Cria a div da tarefa (mesmo código do btn.addEventListener)
        const newDiv = document.createElement('div');
        newDiv.className = 'chield';
        newDiv.id = id;

        const newP = document.createElement('p');
        newP.textContent = taskText;

        const newBtn = document.createElement('button');
        newBtn.className = 'btn-chield';
        newBtn.textContent = 'done';
        newBtn.id = `b${numId}`;

        newDiv.appendChild(newP);
        newDiv.appendChild(newBtn);
        list.appendChild(newDiv);  // Adiciona no final (já está ordenado)

        // Adiciona evento de remover
        newBtn.addEventListener("click", () => {
            deletarCookie(newDiv.id);
            newBtn.parentElement.remove();
        });

        console.log(`📋 Tarefa carregada: "${taskText}"`);
    });
}


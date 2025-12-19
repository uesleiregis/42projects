// ============================================================
// EXEMPLO DIDÁTICO: COOKIES EM JAVASCRIPT
// ============================================================
// Cookies são pequenos textos salvos no navegador do usuário.
// Formato: "nome=valor; expires=DATA; path=/"
// ============================================================

// ------------------------------------------------------------
// 1. CRIAR (SALVAR) UM COOKIE
// ------------------------------------------------------------
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

// ------------------------------------------------------------
// 2. LER UM COOKIE
// ------------------------------------------------------------
function lerCookie(nome) {
    // document.cookie retorna TODOS os cookies em uma string:
    // "nome1=valor1; nome2=valor2; nome3=valor3"
    
    const cookies = document.cookie.split('; '); // Separa em array
    
    for (let cookie of cookies) {
        const [chave, valor] = cookie.split('='); // Separa nome e valor
        
        if (chave === nome) {
            console.log(`📖 Cookie "${nome}" encontrado: "${decodeURIComponent(valor)}"`);
            return decodeURIComponent(valor);
        }
    }
    
    console.log(`❌ Cookie "${nome}" não encontrado`);
    return null; // Não encontrou
}

// ------------------------------------------------------------
// 3. DELETAR UM COOKIE
// ------------------------------------------------------------
function deletarCookie(nome) {
    // Para deletar, define uma data de expiração no PASSADO
    document.cookie = `${nome}=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/`;
    console.log(`🗑️ Cookie "${nome}" deletado`);
}

// ============================================================
// EXEMPLO PRÁTICO: SALVANDO TAREFAS DA SUA TODO LIST
// ============================================================

// Array para guardar as tarefas
let tarefas = [];

// Salva o array de tarefas no cookie
function salvarTarefasNoCookie() {
    // Converte o array para texto (JSON)
    const tarefasTexto = JSON.stringify(tarefas);
    salvarCookie('minhasTarefas', tarefasTexto, 7); // Expira em 7 dias
}

// Carrega as tarefas do cookie
function carregarTarefasDoCookie() {
    const tarefasTexto = lerCookie('minhasTarefas');
    
    if (tarefasTexto) {
        // Converte o texto de volta para array
        tarefas = JSON.parse(tarefasTexto);
        console.log('📋 Tarefas carregadas:', tarefas);
        return tarefas;
    }
    
    return []; // Retorna array vazio se não houver tarefas salvas
}

// ============================================================
// TESTANDO NO CONSOLE DO NAVEGADOR
// ============================================================
// Abra o console (F12) e teste:

// 1. Salvar uma tarefa:
//    salvarCookie('tarefa1', 'Estudar JavaScript', 7);

// 2. Ler a tarefa:
//    lerCookie('tarefa1');

// 3. Deletar a tarefa:
//    deletarCookie('tarefa1');

// 4. Salvar várias tarefas:
//    tarefas = ['Estudar JS', 'Fazer exercícios', 'Revisar código'];
//    salvarTarefasNoCookie();

// 5. Carregar tarefas salvas (mesmo após recarregar a página):
//    carregarTarefasDoCookie();

// ============================================================
// COMO USAR NO SEU TODO.JS
// ============================================================
/*
    No seu código, você pode:

    1. Ao CRIAR uma tarefa:
       tarefas.push(taskText);
       salvarTarefasNoCookie();

    2. Ao REMOVER uma tarefa:
       tarefas = tarefas.filter(t => t !== taskText);
       salvarTarefasNoCookie();

    3. Ao CARREGAR a página (início do script):
       const tarefasSalvas = carregarTarefasDoCookie();
       tarefasSalvas.forEach(texto => {
           // Criar a div da tarefa na tela
       });
*/

console.log('🍪 Arquivo cookies-exemplo.js carregado!');
console.log('📌 Use as funções: salvarCookie(), lerCookie(), deletarCookie()');
console.log('📌 Para tarefas: salvarTarefasNoCookie(), carregarTarefasDoCookie()');

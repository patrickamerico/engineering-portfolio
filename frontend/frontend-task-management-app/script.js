// Seleciona elementos do DOM
const taskInput = document.getElementById('taskInput');
const addTaskBtn = document.getElementById('addTaskBtn');
const taskList = document.getElementById('taskList');

// Função para criar um item de tarefa
function createTaskItem(taskText) {
  const li = document.createElement('li');

  // Texto da tarefa
  const span = document.createElement('span');
  span.classList.add('task-text');
  span.textContent = taskText;

  // Ao clicar no texto, marca/desmarca como concluída
  span.addEventListener('click', () => {
    li.classList.toggle('completed');
  });

  // Botão de deletar
  const deleteBtn = document.createElement('button');
  deleteBtn.classList.add('delete-btn');
  deleteBtn.textContent = '×'; // Ícone de fechar

  deleteBtn.addEventListener('click', () => {
    taskList.removeChild(li);
  });

  li.appendChild(span);
  li.appendChild(deleteBtn);

  return li;
}

// Função para adicionar tarefa
function addTask() {
  const taskText = taskInput.value.trim();

  if (taskText === '') {
    alert('Por favor, digite uma tarefa.');
    return;
  }

  const taskItem = createTaskItem(taskText);
  taskList.appendChild(taskItem);

  taskInput.value = '';
  taskInput.focus();
}

// Eventos
addTaskBtn.addEventListener('click', addTask);

// Permitir adicionar tarefa com Enter
taskInput.addEventListener('keypress', (e) => {
  if (e.key === 'Enter') {
    addTask();
  }
});

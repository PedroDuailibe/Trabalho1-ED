# Sistema de Reserva de Salas - Trabalho 1 Estrutura de Dados (EMAp-FGV)

Este projeto implementa um sistema de gerenciamento de reservas de salas em C++. O sistema permite alocar turmas/disciplinas em salas disponíveis, respeitando a capacidade de alunos de cada sala e evitando conflitos de horários.
Supomos que uma turma/disciplina poderá requisitar uma sala apenas uma única vez. Isso implica que o nome da disciplina é único dentro do sistema.

As principais funcionalidades incluem:
- **Reserva de Salas (`reserve`)**: Verifica se há uma sala com capacidade suficiente e sem conflito de horário para o dia solicitado. Se houver, a reserva é efetivada.
- **Cancelamento (`cancel`)**: Permite cancelar a reserva de um curso específico informando apenas o seu nome.
- **Visualização da Grade (`printSchedule`)**: Exibe o cronograma completo de reservas, organizado por sala e por dia da semana.

## Instruções de Compilação
Para compilar o projeto, você precisa de um compilador C++ (como o `g++`). 

Abra o terminal na pasta onde os arquivos estão localizados e execute o seguinte comando:

```bash
g++ main.cpp ReservationRequest.cpp ReservationSystem.cpp -o sistema_reservas
```

## Instruções de Execução
Para executar o projeto, abra o terminal e execute o comando:

```bash
./sistema_reservas
```

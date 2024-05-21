# `Monitor de Vagas de Estacionamento`
# `Parking Lots Monitor`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| Eduardo Pereira Tejada  | 183451  | Eng. Elétrica|
| Gabriel Dias Vasconcelos  | 248134  | Eng. Elétrica|


## Descrição do Projeto
O projeto visa solucionar o problema de encontrar espaços de estacionamento disponíveis. Oferecendo uma solução automatizada e inteligente para melhorar a experiência dos usuários, bem como a eficiência no uso das vagas. Podem se beneficiar dessa ideia diversos estabelecimentos comerciais como shoppings e supermercados e ainda leva vantagens aos motoristas individuais. O monitor de vagas agrega valor econômico às empresas aumentando o fluxo de clientes, que perderão menos tempo presos no estacionamento procurando um lugar vago e portanto ficarão mais propensos à retornarem ao estabelecimento futuramente, além poder vir a ser útil para a segurança e extração de dados sobre o padrão de uso do estacionamento.


## Descrição Funcional
![Diagrama funcional do sistema](https://github.com/Gabriel-Diasss/ea075-2024.1/blob/main/projetos/monitor_de_vagas/imagens/diagrama_funcional.png?raw=true)

### Funcionalidades
O sistema deve ser capaz de identificar quais vagas estão ocupadas através de um sensor de presença, computar quantos espaços ainda se encontram disponíveis e reportar esses resultados para os usuários do estacionamento através de um painel LED.

### Eventos
Evento 1: novo carro solicitar um lugar pra estacionar;\
Evento 2: carro desocupar uma vaga do estacionamento;\
Evento 3: estacionamento lotado;\
Evento 4: estacionamento deixa de estar lotado.

### Tratamento de Eventos
Evento 1: verificar se existem vagas disponíveis, reportar o resultado e marcar a vaga como ocupada;\
Evento 2: registrar vaga como liberada no sistema;\
Evento 3: na entrada, reportar que o estacionamento está lotado direcionando para um estacionamento na rua;\
Evento 4: reportar a liberação de vagas na entrada.

## Descrição Estrutural do Sistema
![Diagrama de blocos do sistema](https://raw.githubusercontent.com/Gabriel-Diasss/ea075-2024.1/main/projetos/monitor_de_vagas/diagrama_monitor_estacionamento.drawio.svg)

## Especificações (⚠️ NOVO ⚠️)

### Especificação Estrutural

> (Se preferir, adicione um link para o documento de especificação estrutural)
> 
> Entende-se por estrutural a descrição tanto das características elétricas e temporais como das restrições físicas de cada bloco funcional.
> Nessa etapa do projeto, ainda não será solicitado o diagrama elétrico mas espera-se que já estejam identificados os componentes e circuitos integrados propostos
> para implementação do sistema embarcado proposto.
> 
> Como o projeto de um sistema embarcado é centralizado nas tarefas, recomenda-se iniciar com a definição dos periféricos de entrada e saída (atuadores e/ou sensores) apropriados para o
> sistema. Pode ser necessário definir um endereço distinto para cada um deles. 
> Este endereço será utilizado pela unidade micro-controladora para acessá-los tanto para leitura como para escrita.

> Nesta etapa do projeto espera-se que a unidade micro-controladora seja definida.
> Tendo definidos os periféricos e a memória, é possível projetar um decodificador de endereços
> que converte o endereço referenciado no programa em sinal *Chip Select – CS* do dispositivo
> correspondente, habilitando-o para realizar um ciclo de leitura ou de escrita.
> 
> Nesta etapa do projeto espera-se que sejam identificada também a eventual necessidade do projeto de circuitos de interface para os periféricos do projeto.
> Assim, devem ser incluídos na especificação, se necessário:
> - conversores AD e DA;
> - padrões de comunicação a serem adotados;
> - circuitos de sincronização de sinais temporais.
> 
> Finalmente, deve-se especificar as restrições físicas e ambientais de funcionamento do circuito, tais como limites mecânicos
> (altura, largura, profundidade) e limites de dissipação térmica.

### Especificação de Algoritmos 

> (Se preferir, adicione um link para o documento de especificação de algoritmos).
> 
> Deve ser elaborado para CADA evento o algoritmo de tratamento deste evento. Com base no
> tamanho de cada algoritmo, estima-se o tamanho de memória necessária para armazenar todos
> os programas e os dados associados. Isso permitirá especificar a memória a ser utilizada e o
> espaço onde serão armazenados os programas. O algoritmo de tratamento de evento pode
> ser representado graficamente por um fluxograma. Recomenda-se usar símbolos gráficos consistentes 
> com a norma internacional ISO 1028-1973 e IS0 2972-1979.

## Referências
  Notas de aula de EA075 \
  https://www.sofit4.com.br/blog/controle-de-entrada-e-saida-de-veiculos/ \
  https://autopark.com.br/tecnologia-e-automatizacao-para-estacionamentos/

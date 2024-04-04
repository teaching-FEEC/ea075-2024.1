# `Gate driver de MOSFET`
# `MOSFET Gate driver`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
>| Gabriel Tavares Coluccini Francisco  | 239640  | Eng. Elétrica|
>| João Pedro Souza Pascon  | 239733  | Eng. Elétrica|

## Descrição do Projeto

Um Gate Driver de MOSFET está associado ao controle de forma específica e coordenada de chaves MOSFETs, como por exemplo um inversor de potência. No atual contexto econômico global, podemos destacar as enormes possibilidades de mercados que esses dispositivos encontrarão em transição energética e eletrificação veicular, sem contar as indústrias já bem consolidadas que utilizam esses equipamentos para controle de motores.

Os usuários são vastos e variados. Podemos citar usinas sucroalcooleiras,  celulose (muito fortes aqui na região sudeste com nomes como Raízen, São Martinho) geradoras, transmissoras e distribuidoras (que cada vez mais adotam a eletrônica de potência, como CPFL e NeoEnergia). Além das novas áreas, como novos parques eólicos (muito proeminentes nas regiões sul e nordeste); parques solares; novas usinas de etanol de milho; além da eletrificação veicular que traz uma grande gama de novos compradores em potencial.

No cenário macroeconômico global, estamos diante de um ciclo de cortes nas taxas de juros, tanto do FED quanto BC, fazendo com que investimentos em reservas nacionais com baixíssimo risco ofereçam um retorno mais baixo. Como consequência, cria-se um cenário em que investidores precisam tomar mais riscos a fim de obter bons retornos, tornando o ciclo de 2024 um momento embrionário de novos projetos e empreendimentos.
 
Apesar dos bons panoramas, é preciso ter em mente que os desafios de mercado ainda são enormes, uma vez que este setor é dominado por gigantes multinacionais (como Siemens; RockWell; ABB e até mesmo WEG) com produtos muito bem estabelecidos e alto poder de investimento. Além disso, muitas vezes essas companhias possuem linhas completas, isto é: motores, controladores, sensores e softwares plug and play, e vendem esse pacote como um conjunto, conseguindo assim um maior poder de barganha frente a um concorrente de menor tamanho.

O game changer desse mercado, estaria nas novas tecnologias de MOSFETs utilizando os materiais WBG – como SiC e GaN –  uma vez que essa tecnologia ainda não está bem consolidada e em constante avanço. O aprofundamento em nuances destes materiais alongaria o corpo deste texto para o projeto específico desta disciplina, mas, é preciso ter consciência da importância destes materiais para a viabilização econômica do dispositivo.

Dessa forma, para o escopo desta disciplina, propõe-se um modelo rudimentar de gate driver. Com o objetivo de criar uma curva de aprendizado e familiarização com o sistema, atuando em um half-bridge com carga indutiva para onda senoidal. Chamamos o modelo de “rudimentar” porque um dispositivo deste, em estado da arte, é um trabalho para um time de vários engenheiros e com anos de experiência, sendo impossível trazer um dispositivo deste para o escopo desta disciplina


 ### Funcionalidades
 
Embora seja fato que diversos gate drivers comerciais já existentes e bem estabelecidos comercialmente propõem inúmeras funções como: operações do MOSFET em regiões de triodo; adaptabilidade de Vgs; e, nos mais avançados, controle ativo. O projeto proposto não visa chegar em tal ponto de adaptabilidade e escalabilidade, mas sim, permitir um modelo base para criar o início de uma curva de aprendizado e, se possível, futuras melhorias.

Dessa forma, como funcionalidade do projeto, propomos a implementação de um algoritmo em um DSP, que realiza a leitura de potenciômetros, a fim controlar sua frequência de operação e amplitude da onda senoidal resultante de uma fonte de corrente contínua.

### Configurabilidade

Duas configurações de leitrua devem ser feitas: 
- Ler o potênciometro de frequência
- Ler o potênciometro de amplitude

 ### Tratamento de Eventos

 Os eventos a serem tratados pelo sistema e que podem ser considerados como periódicos são aqueles que devem ser tratados na geração de um PWM com carrier technique.

- Monitoramento dos potenciômetros
- Monitoramento da tensão de saída

Os eventos a serem tratados pelo sistema e que podem ser considerados como não-periódicos, são:

 - Ativação do estado proibido do MOSFETs

## Referencias

RASHID, M. H. (2001) Power Electronics Handbook

J. F. Guerreiro, H. Guillardi and J. A. Pomilio, "Design Procedures and Prototyping of a
Full-Bridge High Frequency Power Inverter," 2019 IEEE 15th Brazilian Power Electronics
Conference and 5th IEEE Southern Power Electronics Conference (COBEP/SPEC), Santos, Brazil,
2019, pp. 1-6, doi: 10.1109/COBEP/SPEC44138.2019.9065318.
keywords: {MOSFET;Logic gates;Capacitors;Gate
drivers;Oscillators;Inverters;Switches;MOSFETs;Power Converter;Inverter;High Switching
Frequency}







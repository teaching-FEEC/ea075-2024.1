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

	Um Gate Driver de MOSFET está associado ao controle de forma específica e coordenada de chaves MOSFETs, como por exemplo um inversor de potência. No atual contexto econômico global, podemos destacar as enormes possibilidades de mercados que esses dispositivos encontrarão em transição energética e eletrificação veicular, sem contar as indústrias já bem consolidadas.

No cenário macroeconômico global, estamos diante de um ciclo de cortes nas taxas de juros, tanto do FED quanto BC, fazendo com que investimentos em reservas nacionais com baixíssimo risco ofereçam um retorno mais baixo. Como consequência cria-se um cenário em que investidores precisam tomar mais riscos a fim de obter bons retornos, trazendo o ciclo de 2024 um momento embrionário de novos projetos e empreendimentos.
 
Apesar dos bons panoramas, é preciso ter em mente que os desafios de mercado ainda são enormes, uma vez que este setor é dominado por gigantes multinacionais (como Siemens; RockWell; ABB e até mesmo WEG) com produtos muito bem estabelecidos e alto poder de investimento. Além disso, muitas vezes essas companhias possuem linhas completas, isto é: motores, controladores, sensores e softwares plug and play, e vendem esse pacote como um conjunto, conseguindo assim um maior poder de barganha frente a um concorrente de menor tamanho.
O game changer desse mercado, estaria na nova tecnologia de MOSFETs utilizando os materiais WBG – como SiC e GaN –  uma vez que essa tecnologia ainda não está bem consolidada e em constante avanço. O aprofundamento em nuances destes materiais alongaria o corpo deste texto para o projeto específico desta disciplina, mas, é preciso ter consciência da importância destes materiais para a viabilização econômica do dispositivo.
Isso porque, para o escopo desta disciplina, propõe-se um modelo rudimentar de gate driver. Com o objetivo de criar uma curva de aprendizado e familiarização com o mecanismo, atuando em um half-bridge com carga indutiva para onda senoidal. Chamamos o modelo de “rudimentar” porque um dispositivo deste, em estado da arte, é um trabalho para um time de vários engenheiros e com anos de experiência e não um trabalho para dois alunos de graduação em um semestre – tampouco fora pontuado como objetivo do trabalho a implementação de tal.
	Os usuários são vastos e variados. Podemos citar as diversas usinas de açúcar e etanol,  celulose (muito fortes aqui na região sudeste com nomes como Raízen, São Martinho) geradoras, transmissoras e distribuidoras (que cada vez mais adotam a eletrônica de potência, com nomes como CPFL, NeoEnergia). Além das novas áreas, como novos parques eólicos (muito proeminentes nas regiões sul e nordeste) e parques solares; além da eletrificação veicular com controle de motores e estações de carregamento.

 ### Funcionalidades
 
 Embora seja fato que diversos gate drivers comerciais já existentes e bem estabelecidos comercialmente propõem inúmeras funções como: operações do MOSFET em regiões de triodo; adaptabilidade de Vgs; e, nos mais avançados, controle ativo. O projeto proposto não visa chegar em tal ponto de adaptabilidade e escalabilidade, mas sim, permitir um modelo base para ser evoluído futuramente e uma necessária curva de aprendizado para os engenheiros projetistas.
Dessa forma, como funcionalidade do projeto, entende-se o controle de um par de MOSFETs a fim de criar uma onda senoidal a partir de uma fonte contínua.

### Configurabilidade

Algumas configurações que podem ser incluídas seria o resistor de saída do gate driver, diretamente relacionado com o tempo de transiente da chave e amortecimento da onda. Entretanto, não acredito ser possível, tampouco conveniente, detalhar isso nesse momento ainda do projeto.
	Em dispositivos mais avançados pode haver a inclusão de sistemas de proteção para garantir a segurança e a integridade dos sistemas nas mais diversas condições, como proteções contra a sobrecorrente e sobretensão e acoplamentos ópticos.

 ### Tratamento de Eventos

 Os eventos a serem tratados pelo sistema e que podem ser considerados como periódicos são aqueles que devem ser tratados na geração de um PWM com carrier technique.

- Monitoramento da tensão de saída, utilizados para detectar e responder a eventos de sobrecorrente, garantindo a malha de controle do sistema.

Os eventos a serem tratados pelo sistema e que podem ser considerados como não-periódicos, são:

Ativação do estado proibido do MOSFETs

## Referencias

RASHID, M. H. (2001) Power Electronics Handbook







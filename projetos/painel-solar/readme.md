# `Painéis Solares de Inclinação Adaptável`
# `Adaptive Slope Solar Panels`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Mateus Alves Silva | 239856 | Eng. Elétrica |
> | Nathália Kaori Gondo | 239903 | Eng. Elétrica |


## Descrição do Projeto
Com o aumento da demanda por energias limpas e renováveis, como a solar, em residências e indústrias, a necessidade de maximizar a captação de energia solar tornou-se fundamental. No entanto, os sistemas de painéis solares fixos muitas vezes não conseguem se adaptar adequadamente às variações na incidência solar ao longo do dia. Para enfrentar esse desafio, propõe-se um sistema embarcado para automatizar o ajuste da inclinação do painel solar, garantindo uma ótima captação de energia solar em todas as horas do dia. Esse ajuste acompanha o movimento do sol, mantendo-o perpendicular com os raios incidentes, maximizando assim sua geração.

O sistema funciona através da detecção da intensidade e direção da luz solar por meio de sensores especializados. Esses sensores fornecem dados da intensidade luminosa, permitindo que uma unidade de controle calcule o ângulo ideal de inclinação do painel solar. Com base nesse cálculo, algoritmos de controle ajustam a inclinação do painel solar em tempo real, garantindo que este esteja sempre posicionado de forma ótima para captar a máxima quantidade de energia solar possível.

Além de contribuir para o avanço da tecnologia renovável, esse sistema oferece benefícios econômicos significativos. A eficiência na captação de energia está diretamente ligada ao ângulo de incidência dos raios solares na placa, o que resulta em uma maior rentabilidade dos investimentos em energia solar. Assim, ao maximizar a geração de energia solar de forma eficiente e econômica, o sistema não só reduz os custos operacionais, mas também aumenta a viabilidade e sustentabilidade dos sistemas de energia renovável.


## Descrição Funcional
O sistema opera em tempo real, monitorando com precisão a intensidade da luz solar incidente sobre o painel solar em busca da angulação ideal para maximizar a geração de energia. Isso é alcançado por meio do controle de um servo motor, cuidadosamente ajustado para posicionar os painéis de forma a otimizar sua exposição aos raios solares. O servo motor, conectado aos painéis através de um eixo, oferece ajustes dinâmicos e contínuos, garantindo que eles permaneçam sempre na posição mais vantajosa em relação à incidência solar, idealmente perpendicular aos raios solares.

O monitoramento da incidência solar é centralizado no dispositivo Inversor do sistema, que não só fornece informações em tempo real sobre a geração de energia, mas também atua como o principal ponto de comunicação para o controle do sistema. Além disso, um sensor fotossensível é incorporado como uma camada adicional de segurança e redundância. Esse sensor garante uma confiabilidade ainda maior na medição da intensidade da luz solar, assegurando uma operação robusta e resiliente do sistema mesmo em condições adversas.

Os dados coletados pelo dispositivo Inversor e pelo sensor fotoresistivo são então processados por um microcontrolador, que implementa um algoritmo de controle inteligente. Este algoritmo é projetado para otimizar continuamente a inclinação dos painéis solares, iniciando com uma angulação inicial de referência e, em seguida, realizando varreduras comparativas. O servo motor é ajustado de forma dinâmica com base nas informações recebidas, parando seu movimento quando a eficiência energética máxima é alcançada. Isso é determinado quando uma redução na eficiência é detectada em relação ao valor anterior, indicando que o ângulo ideal foi encontrado.

Em resumo, esse sistema integrado oferece um controle preciso e adaptativo da inclinação dos painéis solares, garantindo uma captação máxima de energia solar ao longo do dia. Ao combinar tecnologia de monitoramento, controle e robustez, o sistema é capaz de operar de forma confiável e eficiente, contribuindo significativamente para a eficiência energética da geração fotovoltaica. Um esquema do sistema pode ser visto na imagem a seguir.

![image](https://github.com/nathaliagondo/ea075-2024.1/assets/165518289/a88782cf-e8c2-4046-9547-955450b393e3)

Figura 1. Representação do sistema embarcado - Painéis solares de inclinação adaptável.

### Funcionalidades
1. _Sun tracking_: o sistema irá monitorar a posição solar usando sensores e ajustando o ângulo de inclinação dos painéis solares para garantir a maior exposição aos raios incidentes.
2. Controle da angulação dos painéis solares.
3. Verificação de luminosidade: verifica se a luminosidade está acima de um _threshold_ para permitir a operação.
4. Suspensção do sistema em caso de luminosidade baixa.
5. Interface com o usuário: uma interface que permita o usuário configurar, ajustar o sistema além de apresentar os dados de produção de energia além de informações operacionais do dispositivo.
6. Maximização da energia produzida: algoritmo de controle que garanta a máxima geração energética com base na adaptação da angulação do painel solar. Os dados serão processados por meio da tensão e corrente recebidas pelos painéis.
7. Comunicação _wireless_: o sistema deverá possuir comunicação sem fio para enviar informações dos sensores e receber dados de controle e configuração de um aplicativo para smartphone.
8. Gerenciamento de energia: o sistema será alimentado com a energia solar gerada pelo próprio painel que alimentará uma bateria (usada como _backup_). A bateria funcionará como um suporte para estabilização da tensão fornecida ao dispositivo. O gerenciamento de energia é essencial para otimizar o consumo de energia e prolongar o tempo de funcionamento do dispositivo.
9. Identificação de erro no sistema ou condição extrema: verificar esforço extra que o motor é submetido ou falha de energia.
10. Retornar a uma posição segura em caso de algum erro ou para manutenção.
11. Sistema de bateria como _backup_ de energia com recarga automática.


### Configurabilidade
1. Faixa de ângulo de varredura: define os valores máximos e mínimos do ângulo que os painéis podem ser inclinados.
2. Frequência do ajuste da posição: define de quanto em quanto tempo o sistema irá realizar os ajustes de inclinação.
3. Limite mínimo de luminosidade para o sistema operar  para evitar desperdício de energia.
4. Posição inicial que o sistema irá começar processo de varredura
5. Posição segura para caso erro no sistema ou condição climática extrema ou para manutenção.
6. Velocidade da mudança da inclinação dos painéis.
7. Tempo de funcionamento máximo.


### Eventos
- Eventos periódicos:
1. Período útil de geração de energia (diário, a cada 24 horas): o período do dia durante o qual o sistema está ativo para captar energia solar e gerar eletricidade. Começando ao nascer do sol e terminando ao pôr do sol, é o intervalo em que a intensidade da luz solar é suficientemente alta para uma produção eficaz de energia.
2. Mudança da posição do sol (diário, a cada poucos minutos - constante): ao longo do dia, a posição do sol no céu se desloca gradualmente devido à rotação da Terra. Essa mudança afeta a quantidade de luz solar que atinge os painéis solares. O sistema deve ajustar a inclinação dos painéis para maximizar a absorção de energia solar, geralmente mantendo-o perpendicular aos raios incidentes.
3. Mudança nas estações do ano (sazonal, a cada três meses, com mudanças graduais entre uma estação e outra): as estações do ano afetam a intensidade e a duração da luz solar incidente devido à inclinação do eixo da Terra. O sistema deve ajustar sua operação e estratégias de captação de energia para otimizar o aproveitamento da luz solar em cada estação.
- Eventos não-periódicos:
4. Condições adversas (variável, depende da frequência e duração das condições): momentos em que as condições climáticas, como nebulosidade, reduzem a intensidade da luz solar disponível para captação. Isso pode resultar em uma diminuição temporária na produção de energia.
5. Condições extremas (variável, depende da frequência e gravidade das condições): eventos climáticos severos, como tempestades e ventanias, que representam riscos para às placas solares. Nessas situações, medidas de segurança devem ser ativadas para proteger os componentes, levando-o à posição referencial.
6. Manutenção das placas solares ou dos componentes do sistema (variável, depende do cronograma de manutenção de cada componente): eventos planejados para garantir o bom funcionamento e a longevidade do sistema. Isso inclui inspeções regulares, limpeza de painéis solares para melhor obtenção dos dados e substituição de peças desgastadas.
7. Bateria fraca (variável, condicionada pelo padrão de consumo do sistema): indica que a carga da bateria de armazenamento de energia atingiu um nível baixo. Isso pode ocorrer devido a um consumo excessivo de energia ou a uma incapacidade de recarga adequada das placas solares.
8. Interação do usuário (variável de acordo com a necessidade do usuário): dedicado quando o usuário interage com o sistema, como ajustar configurações, monitorar o desempenho ou receber notificações sobre o status do sistema.
9. Falhas no sistema (imprevisível, dependendo da natureza e gravidade da falha): ocorrência de problemas ou mau funcionamento no sistema solar que exigem intervenção técnica. Isso pode incluir falhas de hardware, erros de software ou interrupções na geração de energia.

### Tratamento de Eventos
1. Período útil de geração de energia: 
    - Iniciar automaticamente os painéis solares e o sistema de geração de energia ao nascer do sol e ajustar a inclinação dos painéis solares ao longo do dia para acompanhar o movimento do sol, de modo a maximizar a captação de energia.
    - Desativar o sistema de busca pelo ângulo ótimo no pôr do sol e monitoramente da produção de energia para evitar a consumo de energia desnecessária durante a noite.
2. Mudança da posição do sol:
    - Ajustar a inclinação dos painéis solares em tempo real para garantir que estejam sempre alinhados da maneira mais eficiente possível com a incidência de luz solar.
    - Monitorar continuamente a produção de energia e consumo, realizando ajustes automáticos na inclinação ao longo do dia para acompanhar o movimento do sol e otimizar a eficiência energética.
3. Mudança nas estações do ano:
    - Com base na data e posição do sol, ajustar as configurações de inclinação dos painéis solares e os algoritmos de captação de energia para otimizar o desempenho de acordo com as condições específicas de cada estação.
    - Adaptar as estratégias de armazenamento e uso de energia para melhor atender às necessidades sazonais de energia.
4. Condições adversas:
    - Monitorar a ocorrência de mudanças na obtenção dos dados, para ajusar as operações dos painéis solares, lidando com a redução na intensidade da luz solar.
    - Implementar medidas de economia de energia para preservar a energia disponível durante períodos de baixa produção.
5. Condições extremas:
    - Identificar ventanias e tempestades por meio de variações bruscas no torque do servomotor. 
    - Ativar um modo de segurança que retraia os painéis solares e desative temporariamente a geração de energia para proteger os componentes do sistema contra danos.
    - Emitir alertas aos usuários sobre as condições climáticas extremas.
6. Manutenção das placas solares ou dos componentes do sistema:
    - Agendar automaticamente tarefas de manutenção com base em intervalos predefinidos ou em condições específicas do sistema.
    - Desativar temporariamente os painéis solares e o sistema durante a manutenção para garantir a segurança durante as limpezas e as substituições de componentes desgastados.
7. Bateria fraca:
    - Monitorar continuamente o nível de carga da bateria de armazenamento de energia.
    - Reduzir automaticamente o consumo de energia ou ajustar as operações dos painéis solares para preservar a energia restante da bateria.
    - Emitir alertas aos usuários sobre a bateria fraca.
8. Interação do usuário:
    - Prioridade em relação aos demais eventos, respondendo rapidamente às solicitações.
    - Interface intuitiva sistema-usuário
9. Falhas no sistema:
    - Tentar realizar correções automáticas, quando possível, e diagnósticos das falhas.
    - Se não for possível corrigi-lo, desativar o sistema e emitir alertas ao usuário indicando as falhas.


## Descrição Estrutural do Sistema
O sistema possuirá um painel ou grupo de painéis solares ligados a um eixo de rotação conectado a um servo motor industrial responsável por permitir a dinâmica do sistema. Além disso, deve possuir sensores fotossensíveis para interpretar a luminosidade e a luz incidente nos painéis, possuir um microcontrolador com comunicação sem fio para que consiga enviar e receber dados de um usuário além de interpretar o algoritmo de controle do sistema. Precisa-se de uma bateria que garanta que o sistema funcione mesmo com quedas de energia.

Em primeiro lugar haverá a inicialização do sistema onde os componentes de sensoriamento (sensores fotosenssíveis) e do servo motor irão ser ligados e calibrados, assim como os componentes de comunicação. Logo após, o sistema irá realizar uma checagem dos componentes verificando algum erro ou condições extremas de clima. Caso haja algum problema, o sistema irá se manter em uma posição segura definida pelo usuário, além de comunicá-lo via comunicação _wireless_. O sistema deve checar também se sua fonte de alimentação é sua bateria interna de _backup_. Caso afirmativo, ele também deve comunicar ao usuário a falta de energia.

Se a checagem do erro passar sem problemas, o servo motor deve ajustar o eixo a uma posição inicial de operação também pré-definida pelo usuário, e verificar se há a necessidade de recarregar a bateria de _backup_. Caso seja preciso, faz-se a carga da mesma. Após a máquina na posição correta, o sistema verifica a luminosidade do dia por meio dos fotossensores e de dados recebidos do inversor do painel solar e, caso essa luminosidade não ultrapasse o valor mínimo, o sistema é suspendido automaticamente. Caso contrário, ele inicia o processo de ajuste de máxima geração de energia, ajustando a posição dos painéis pelo servo motor, checa a incidência solar e novamente pelos sensores e pela energia produzida, se necessário, se ajusta novamente até encontrar a posição ideal. Quando encontrada essa posição, permanecerá nela por um tempo definido pelo usuário. Após esse tempo, o sistema volta a verificar a luminosidade e repete o processo de ajuste de posição. 

Observa-se que o usuário pode interromper a rotina do sistema por seus comandos, podendo inicializar o sistema manualmente, desligar o sistema, suspendê-lo e ainda manter posição de segurança. Após certo tempo, também definido pelo usuário, o sistema se inicializa automaticamente para que ele opere sem a necessidade do usuário ligá-lo sempre no dia-a-dia.

O diagrama das atividades podem ser vistas pela Figura 2. abaixo.

![Inicializar](https://github.com/nathaliagondo/ea075-2024.1/assets/165518289/fc771e96-53b4-4542-a22a-ef8bc89a5591)

Figura 2. Diagrama de blocos dos processos realizados pelo sistema.


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
[1] Silva, Marcelo Allan de Melo. Projeto de suporte com inclinação variável para placas solares residenciais. 2023. 70 f. Trabalho de Conclusão de Curso (Graduação em Engenharia Mecânica) - Departamento de Engenharia Mecânica, Centro de Tecnologia e Geociências, Universidade Federal de Pernambuco, Recife, 2023. Disponível em: https://repositorio.ufpe.br/handle/123456789/50687. Acesso em: 30 de março de 2024.

[2] Ferronato, Régis; Severo, Tiago Cassol. Análise do Rendimento de um Módulo Fotovoltaico com Suporte de Inclinação Variável. In: Congresso Internacional de Tecnologias para o Meio Ambiente, 6., Bento Gonçalves, RS, Brasil, 10-12 de abril de 2018. Bento Gonçalves: UCS, 2018. Disponível em: https://siambiental.ucs.br/congresso/getArtigo.php?id=490&ano=_sexto. Acesso em: 30 de março de 2024.

[3] Cravo, E. (s.d.). Servo Motor: o que é um, como funciona e quais as vantagens? Recuperado de: https://blog.kalatec.com.br/o-que-e-servo-motor/?utm_source=google&utm_medium=cpc&utm_campaign=npbr_search_DSA&utm_id=21012797249&utm_term=&gad_source=1&gclid=CjwKCAjwtqmwBhBVEiwAL-WAYQnYY9Xp7LGsU-SsAqGSzuhZBELNIFGqw1FDFUnbnq8aRlu-L0fVyBoC-r4QAvD_BwE

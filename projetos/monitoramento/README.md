# `<Sistema de Rastreamento e Monitoramento de Veículos de Frota>`
# `<Fleet Vehicle Tracking and Monitoring System>`

## Apresentação 

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no orimeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Paulo Roberto de Araujo Junior  | 204440  | Eng. Controle e Automação|


## Descrição do Projeto 

>O objetivo principal deste projeto é desenvolver um sistema de rastreamento e monitoramento de veículos de frota que permita o acompanhamento em tempo real da localização dos veículos, além de monitorar e controlar parâmetros críticos como velocidade, tempo de uso e manutenção. Uma das motivações para este projeto surge da experiência na área de consultoria de logística, onde foi possível perceber os prejuízos e perdas de desempenho e controle que as empresas enfrentam por não poderem monitorar e replanejar com horários reais suas entregas e coletas de maneira eficiente. Pretendemos resolver o desafio enfrentado por empresas de logística, transporte e outras organizações com frotas de veículos, fornecendo uma solução eficiente para a gestão e operação desses ativos. Os potenciais usuários incluem empresas de logística e transporte, empresas com frotas de veículos comerciais, serviços de entrega e transporte urbano, e empresas de aluguel de veículos. Estima-se que a implementação desse sistema possa resultar em economia de combustível, redução de custos de manutenção, aumento da vida útil dos veículos e melhoria da eficiência operacional, além de reduzir riscos de roubo e mau uso dos veículos, ajudando também na prevenção de acidentes.


## Descrição Funcional (ATUALIZAR SE NECESSÁRIO)
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar
> Rastreamento em Tempo Real:

> Monitoramento contínuo da localização dos veículos via GPS, fornecendo informações atualizadas sobre sua posição.
> Visualização da localização dos veículos em um mapa digital, permitindo fácil acompanhamento e gerenciamento da frota.
> Monitoramento de Velocidade:

> Registro preciso da velocidade de cada veículo, permitindo análise de padrões de condução e identificação de comportamentos de > risco.
> Geração de alertas em tempo real para velocidades excessivas, promovendo a segurança na direção e reduzindo o risco de acidentes.
> Gestão de Manutenção Proativa:

> Acompanhamento da quilometragem percorrida por cada veículo, gerando notificações quando os prazos de manutenção preventiva se aproximam.
> Otimização do cronograma de manutenções, prevenindo falhas inesperadas e reduzindo custos com reparos.
> Relatórios Detalhados e Personalizáveis:

> Geração de relatórios abrangentes sobre o uso dos veículos, incluindo quilometragem percorrida, tempo de uso, consumo de combustível e outros parâmetros relevantes.
> Personalização dos relatórios de acordo com as necessidades específicas do cliente, permitindo uma análise aprofundada do desempenho da frota.
> Alertas e Notificações Inteligentes:

> Envio de alertas imediatos para comportamentos anormais, como desvios de rota, paradas não autorizadas ou abertura de portas sem autorização.
> Notificações personalizadas para eventos específicos, como início e término de viagens, chegada a destinos predefinidos ou violações de regras de uso.

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.
> O sistema oferece diversas opções de configuração para atender às necessidades específicas de cada cliente:

> Frequência de Atualização:

> Definição da frequência de envio de dados de localização e parâmetros dos veículos, permitindo um equilíbrio entre precisão e consumo de dados.
> Opções personalizáveis para diferentes cenários, desde atualizações em tempo real para rastreamento crítico até atualizações menos frequentes para otimizar o uso de dados.
> Limites de Velocidade:

> Estabelecimento de limites de velocidade personalizados para cada veículo ou zona geográfica, considerando fatores como tipo de veículo, condições de tráfego e leis locais.
> Flexibilidade para ajustar os limites de velocidade de acordo com as necessidades e políticas da empresa, promovendo um ambiente de condução mais seguro.
> Intervalos de Manutenção:

> Configuração de intervalos de manutenção preventiva baseados na quilometragem, tempo de uso ou outros indicadores relevantes para cada tipo de veículo.
> Personalização dos intervalos de acordo com as recomendações do fabricante e as condições reais de operação, garantindo o bom funcionamento dos veículos e otimizando custos.

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?
> O sistema é projetado para tratar diversos tipos de eventos, categorizados em periódicos e não periódicos:

> Eventos Periódicos:

> Envio de Dados de Localização:

> Transmissão da posição GPS de cada veículo para o servidor central a cada 1 minuto, garantindo monitoramento preciso e contínuo da frota.
> Possibilidade de ajustar a frequência de envio de acordo com as necessidades, considerando fatores como precisão desejada e consumo de bateria dos dispositivos embarcados.
Atualização de Parâmetros de Veículo:

> Registro e envio de dados como velocidade, tempo de uso, consumo de combustível e outros parâmetros relevantes a cada 5 minutos.
> Fornecimento de informações valiosas para análise do comportamento dos veículos e identificação de oportunidades de otimização.

> *Tempos de recorrência de eventos foram previamente estipulados, mas poderão ser customizados conforme regra de negócio específica, para atender melhor a necessidade da empresa*

> Eventos Não Periódicos:

> Detecção de Velocidade Excessiva:

> Geração de alertas imediatos para o gestor da frota quando a velocidade de um veículo ultrapassa o limite configurado.
Ações proativas para prevenir comportamentos de risco e garantir a segurança na direção, reduzindo o risco de acidentes e multas.
Alerta de Manutenção:

> Envio de notificação ao gestor da frota quando a quilometragem de um veículo atinge o limite configurado para manutenção preventiva.
> Agendamento proativo de manutenções, prevenindo falhas inesperadas e custos com reparos emergenciais.

### Tratamento de Eventos

> Envio de Dados de Localização:

> Ação: O dispositivo GPS transmite a posição atual do veículo para o servidor central.
> Frequência: A cada 1 minuto (personalizável).
> Dados: Latitude, longitude, data, hora, velocidade e outras informações relevantes.
> Atualização de Parâmetros do Veículo:

> Ação: O dispositivo registra e envia dados do veículo para o servidor central.
> Frequência: A cada 5 minutos (personalizável).
> Dados: Velocidade, tempo de uso, consumo de combustível, odômetro e outros parâmetros relevantes.
> Detecção de Velocidade Excessiva:

> Ação: O sistema gera um alerta imediato para o gestor da frota quando a velocidade do veículo ultrapassa o limite configurado.
> Critério: Limite de velocidade definido pelo gestor para cada veículo ou zona.
> Notificação: Alerta visual e sonoro no sistema de monitoramento, e-mail ou SMS para o gestor.
> Alerta de Manutenção:

> Ação: O sistema envia uma notificação ao gestor da frota quando a quilometragem do veículo atinge o limite configurado para manutenção preventiva.
> Critério: Limite de quilometragem definido para cada tipo de veículo ou com base em outros indicadores.
Notificação: Alerta no sistema de monitoramento, e-mail ou SMS para o gestor, com informações sobre o veículo e a necessidade de manutenção.
Observações:

> A frequência de envio de dados e os limites de velocidade podem ser personalizados de acordo com as necessidades de cada empresa.
O sistema oferece opções flexíveis para configurar alertas e notificações, garantindo que o gestor da frota receba as informações relevantes no momento certo.

> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

## Descrição Estrutural do Sistema (ATUALIZAR SE NECESSÁRIO)
> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.
> 
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.

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

## Referências (ATUALIZAR SE NECESSÁRIO)
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.

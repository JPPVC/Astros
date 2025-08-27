O que eh o Astros
Astros alem de um simulador de corpos celestes ele vai ser uma API de simulacao
fisica onde leis da fisica podem ser adicionadas e retiradas da simulacao na hora da compilacao
alem de outros plugins para adicionar graficos ,logging ,etc
Porem Astros visa implementar uma API comun para simulacao de grandes corpos fisicos

A API vai ser programada 100% em C++ de forma orientada a objetos porem visa ser portatil
para outras linguagems e ecosistemas

Ela efetuara o minimo uso de bibliotecas particulares a um sistema operacional
visando a portabilidade a sistemas tanto linux quanto windows(note que 
ele vais ser incialmente desenvolvido em um ambiente linux)


Milestone1
Criar a base da documentacao da API e criar a arquitetura orientada a plugins

Milestone2
Arquitetura do sistema de login que por si vai ser um plugin para API ou seja 
pode ser na hora do compilacao mudado para o que o programador desejar
O sistema de logging vai primordialmente guardar info no formato JSON
ou seja facilmente legivel pelo sistema e o usuario

Milestone3 
Implementar Lei de Keppler e gravidade de einstein com um sistema de logging
para fazer o display dos dados calculados




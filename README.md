# ft_containers

the aim of the project is re-coding the most common standard template library container and relative functions

## Log del 8 aprile, h 16
### to-do-list
#### vector: on-going
- negli overload di funzioni con template, l'enable-if non deve controllare se il tipo di dato passato è un intero, ma se è un [iteratore](https://stackoverflow.com/questions/4335962/how-to-check-if-a-template-parameter-is-an-iterator-type-or-not)
#### map: on-going
- problema su erase: a livello di RBTree, non vengono eliminati i nodi con due figli
- sono da implementare tutti i metodi. vedi reference
- erase necessita di ritornarte il numero di elementi eliminati (1 o 0)
#### set: on-going
- sono da implementare tutti i metodi. vedi reference
- erase necessita di ritornarte il numero di elementi eliminati (1 o 0)
#### stack: not started

## link utili
- [link](https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/) per implementare albero rosso-nero
- [link](https://programmer.ink/think/use-a-red-black-tree-to-encapsulate-set-and-map-at-the-same-time.html) per implementare
map e set con alebro rosso-nero.


## useful information
- obviously read and understand deeply the subject
- You can find all the information for understand the Containers on the references sites
- first of all, understand the std::allocator class. It's FOUNDAMENTAL!
- Personally I found this project really difficult, the only sugggestion I can give to you is take your time
to understand the container then try to code, if it fail, try again, and do not stop doing that.

# ft_containers

the aim of the project is re-coding the most common standard template library container and relative functions

## testing phase
### Log del 27 aprile, h 19
#### vector:
- timeout on assign
- slow on swap
#### set:
- slow on erase (pos & iter)
- slow on upper/lower_bound
- failed on using allocator
#### map: on-going
- slow on erase (pos & iter)
- slow on upper/lower_bound
- failed on using allocator
#### stack:
- leaks on constructor

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

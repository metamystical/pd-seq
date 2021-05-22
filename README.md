## pd-seq
Accessory for [[purdie ] object](https://github.com/metamystical/pd-purdie) for Pure Data.

### Description

[seq ] ouputs a consecutive sequence of integers of size "size" beginning with "base" in rapid succession. 

Inputs are described in the following table:

| Label    | Input | Type    | Action                                                                                                                                 |
|----------|---------|---------|----------------------------------------------------------------------------------------------------------------------------------------|
| **bang**     | 0       | active   | output the full integer sequence rapid fire |
| **base**     | 0       | passive  | set the starting integer |
| **size**     | 1       | passive  | set the size of the series |

note: the initial values of **base** and **size** can be specified within the object box itself [seq base size ]. Defaults are zero.

### Installation

The seq.c file can be compiled into a Pure Data external using [pure-data/pd-lib-builder](https://github.com/pure-data/pd-lib-builder). Simply place the linked file (e.g. seq.pd_linux) along with the help patch seq-help.pd into the same directory as your patch, or somewhere on the Pd search path (e.g., externals/seq folder).

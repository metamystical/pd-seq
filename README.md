## pd-seq
Accessory for [[purdie ] object](https://github.com/metamystical/pd-purdie) for Pure Data.

### Description

[seq ] ouputs a consecutive sequence of integers of size **size** beginning with **base**. 

Inputs are described in the following table. All selectors can be sent as messages to the left input with arguments as specified:

| Selector     | Input   | Message argument | Effect                                                          |
|--------------|---------|----------|-------------------------------------------------------------------------|
| **bang**     | left    | none   | output the full integer sequence |
| **reset**    | left    | none   | message to restore the initial values of **base** and **size** |
| **fast**     | left    | float (0 or 1) | when toggled, output the series rapid-fire instead of one bang at a time |
| **base**     | middle  | float (truncated to integer)  | set the starting integer |
| **size**     | right   | float (truncated to integer)  | set the size of the series; if negative, sequence is decreasing |

Note: the initial values of **base** and **size** can be specified within the object box itself [seq base size ]. Defaults are zero.

Note: changing any of the inputs (besides **bang**) causes the sequence to restart from **base**.

### Installation

The seq.c file can be compiled into a Pure Data external using [pure-data/pd-lib-builder](https://github.com/pure-data/pd-lib-builder). Simply place the linked file (e.g. seq.pd_linux) along with the help patch seq-help.pd into the same directory as your patch, or somewhere on the Pd search path (e.g., externals/seq folder).

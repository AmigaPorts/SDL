# 30 / / Creating and Using New Layers / Changing a Viewpoint


The [ScrollLayer()](../Includes_and_Autodocs_2._guide/node03A2.html) function changes the portion of a [super bitmap](../Libraries_Manual_guide/node03E9.html) that is
shown by a layer:


```c
    void ScrollLayer( long dummy, struct Layer *layer, long dx, long dy );
```
This function is most useful with [super bitmap](../Libraries_Manual_guide/node03E9.html) layers but can also
simulate the effect on other layer types by adding the scroll offset to
all future rendering.


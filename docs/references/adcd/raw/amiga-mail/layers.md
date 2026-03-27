# Layers


* Use NewLayerInfo() to create, not FattenLayerInfo(), ThinLayerInfo(),
  InitLayers().

* Simple-refresh preserves all of the pixels it can.  Sizing a
  SIMPLE_REFRESH window no longer clears the whole window.

* Speed of layer operations is different.  Don't depend on layer
  operations to finish before or after other asynchronous actions.


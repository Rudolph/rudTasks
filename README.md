# rudTasks
A simple task scheduler library for Arduino. There is probably a much 
better way of doing this, but I don't know it, and this works for me.

This uses a basic "if millis minus last-millis is greater than **_interval_**"
kind of timing. Therefore it can be royally screwed up by functions that
take longer than **_interval_** to run. In other words, do not use this
library for anything remotely critical.

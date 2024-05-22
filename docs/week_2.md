Experienced lots of troubles with the ofArduino and ofSerial libraries this week. Tried lots of examples, broke everything down to a couple very basic programs, nothing worked on the OF side (obviously the arduino side was fine, nothing was wrong with either my Uno or the Teensyduino, although it looks like I might have problems with the teensy in OF, so I might stick with the Uno for now). In the end, the problem was that my OF app didn't have permission to access the device at `dev/ttyACM0` (the arduino). I thought I'd run it with `sudo` priviledges, but maybe not. Either way, the fix was doing a `sudo chown brandon-steinman /dev/ttyACM0` to grant my user... the default user... access to the device at that port. *wack*

At this point, I have demo LED circuits, lots of scattered basic examples to run, but no development on the audio side due to pouring around 7-10 hours into ofArduino and ofSerial. Anyway, shoutouts to my CA Ms. Qiu for coming up with that solution in code review that probably saved my project. I'm psyched to be able to get some momentum going on this again!

### Impactful decisions from this week
- using Firmata protocol, will gravitate toward ofArduino since this is default
- using Uno instead of teensy (forgot to order pin headers and OF might not like teensy)
- `chown` !
- pretty much locked in to this project idea, there's no turning back now!!!

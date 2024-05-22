# Project Proposal

## 1st Idea: Music Visualizer with a twist
I love music and I love my bike and I love arduino and I love C++ (*lol*). I've got a great teensyduino sitting that I want to put to use. It's a match made in heaven.

### High-level overview

I've been biking for so long that I tend to get bored on it without music. I figure that it'd be pretty neat to have some LED matrices (flexible, waterproof) on the body of my bike that bounce kinda like a mixing board/computer music software's volume/gain visualizers do. That particular idea would be really cool for the downtube and top tube, at least.

I imagine biking, laptop in my bag, real long cord going down to a teensyduino in a sleeve on the underside of the seat. Some wires run to LED matrices. Maybe some speakers on the back during summertime. That's my vibe.

### OpenFrameworks libraries and implementation details

This can be broken up into two categories/main libraries: Music and Arduino. For the music part, we start with using the ofSoundPlayer lib to load files and extract data. ofSoundStream can help if I want to actually play the music through that app. ofSoundBuffer will help if the capabilities of ofSoundPlayer to collect the data relevant to visualization aren't sufficient. This portion of the app will then stream the music to my headphones and also break down samples of the music into pieces of data that are important to the visualizer. These components will probably be frequencies, gain, onset of beats, and other sound qualities that strike me as important. If I get small enough diodes, then even the shape of the audio waves could be important (for this case, OF offers FFT capabilities to model the shape of the wave!!!).

The Arduino-related libraries will be important for transmitting the data from my app to the Arduino and its subroutines. It looks like ofxSimpleSerial will be helpful in transmitting my data effectively. 

I'll write some arduino code to translate this into the right display format. I'll test this visually with a window that displays a version of my visualizer and helps test what should be on the LEDs.

Also, I'm not screwing with anybody else's APIs for this app. Just using mp3 files.




## 2nd idea: LAN Stealth game

### High-level overview

A game of stealth (de-emphasized combat) between two players. It'll be expressed in pixel art. Pixel shaders are handled pretty nicely with the help of OFNetwork packets will be send in the UDP protocol, for which there is ample support as well. Not nearly as interested in this one as in the first.. and the 3rd one kinda sucks... I'd have to plan a lot more seriously if I end up dropping the first.








## 3rd idea that I dont like much anymore

This proposal is broken down into the the three main portions of code.

### Machine Learning workload
- my application will be sitting in a GCloud cluster, within that, there are
    1. Volumes that contian the data in MySQL databases
    2. LoadBalancer/NodePorts that manage communication in/outside the cluster and within
    3. A containerized verison of my App
    4. other Kubernetes resources
- This ML workflow will be tested for efficiency in execution for various allocations of K8s resources
- The C++ code here will be doing modelling and trying to fit to data and present its accuracy if possible

### The OF Application
- This is an App for visualizing how K8s resource allocation affects how efficiently workloads are executed
    - The C++ code here will be taking advantage of OF libraries as well as potentially others for this

### The Kubernetes Cluster
- In order to interact with Kubernetes, some scripts will need to be triggered. Bash is scary, and I've been using python all year, buuuut I just learned GoLang so that's what we'll be using!
    - These scripts will trigger various states of LoadBalancer/NodePort configuration and thus will make the experiment happen
    - HOW DO I TRIGGER SCRIPTS WITH C++
- I may be using company compute time for this, or might pay for it on my own or I don't know....
- MySQL and Persistent Volume Claims
- Network config
- Containerizing apps
- Node setup
- cluster/serviceAccount permisisons
- SO MUCH YAML
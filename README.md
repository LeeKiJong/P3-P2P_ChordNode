# P2P_ChordNode
## Table of contents
* What's included
* Operation process
* Functional Introduction
* Example
* Error solution
## What's included
Within the download you'll find the following directories and files, logically grouping common assets and providing both complied and minified variations. You'll see something like this:

* P2P_ChordNode
   * P2P_ChordNode
      * ChordNode.c
      * P2P_ChordNode.vcsproj
      * P2P_ChordNode.vcxproj.filters
   * P2P_ChordNode.sln

## Operation process
1. Clone the repo: `git clone https://github.com/LeeKiJong/P2P_ChordNode.git` 
2. Open the 2+ CMD Prompt
3. Node cmd: `location.../ChordNode 192.168.0.1 <Port>`
4. Function Use
* Node Join: `j` - `Helper Node IP`
* Node Leave: `l`
* File Add: `a` - `File Name`
* File Delete: `d` - `File Name`
* File Download: `s` - `File Name`
* View Finger: `f`
* View Info: `i`
* Toggle Mute Mode: `m`
* View Help Msg: `h`
* Program Quit: `q`

## Functional Introduction
1.  (c)reate: Create the chord network
2.  (j)oin  : Join the chord network
3.  (l)eave : Leave the chord network
4.  (a)dd   : Add a file to the network
5.  (d)elete: Delete a file to the network
6.  (s)earch: File search and download
7.  (f)inger: Show the finger table
8.  (i)nfo  : Show the node information
9.  (m)ute  : Toggle the silent mode
10. (h)elp  : Show the help message
11. (q)uit  : Quit the program

## Example
1.  Node A: Network Create
2.  Node B: Network Join
3.  Node C: Network Join
4.  Node A: File1 Add
5.  Node A: File2 Add
6.  Node B: File3 Add
7.  Node C: File1 Download
8.  Node B: File2 Download
9.  Node A: File3 Download
10. Node C: File4 Add
11. Node D: Network Join
12. Node D: File5 Add
13. Node D: File4 Download
14. Node A: File1 Delete
15. Node C: Network Leave
[[TIP]]
It can be regarded as normal operation when the above execution process proceeds without error.
[[/TIP]]
## Error solution
* forced termination: Message ping-pong error due to network delay  `Restart Or Reboot`
* Mute Mode Error: Ping-pong message send error due to message output. Can't resolve if it's a code issue or a message passing issue

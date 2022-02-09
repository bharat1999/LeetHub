**Explanation**
​
Here the key point is that we cannot flip those O which are part of a chain connected to o at border So we will first find all those O which are connected to borders 0 and change them to some other char let it be ? . Than we are left with O which not connected to border . So we will first flip all of them than iterate over the board again and flip to ? to O again
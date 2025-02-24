## Workshop 2: Getting Down Two the Basics!
### One: Okay, so what exactly are Embedded Systems? 

Well, we can break the topic down in a number of ways, but I like how the team at [geeksforgeeks.org](https://www.geeksforgeeks.org/introduction-of-embedded-systems-set-1/) breaks the topic down into two parts:
> System is a set of interrelated parts/components which are designed/developed to perform common tasks or to do some specific work for which it has been created. 
> Embedded means including something with anything for a reason. Or simply we can say something which is integrated or attached to another thing.
Therefore, they conclude that:
> [An] embedded system is a computational system that is developed based on an integration of both hardware and software in order to perform a given task [...] without human intervention or with little human intervention.

So, as we've discussed before, Embedded Systems are meant to operate independently. However, I want to add a point of clarity to the last point from GeeksforGeeks, just because embedded systems operate with little human intervention, doesn't mean that they need to operate without any human ***interaction***. In fact, some of the most common embedded systems are designed specifically for the purpose of interacting with humans, whether this be the operation of a vehicle, a smart watch, or less commonly: an audience reactive sculpture. Yet, the important thing is that just like a good worker, once they are given a task, they should be able to complete that task on their own. *They're like little elves working in our Christmas castles.* 

### Two: Elves and Binary:
As mentioned above, we have a tiny little elf that does exactly what we ask, how do we tell it what we need? ***i'M sO GlAd yoU aSKeD!*** Binary, the answer is binary! Yes, 01011001 01101111 01110101 00100000 01110010 01100101 01100001 01100100 00100000 01110100 01101000 01100001 01110100 00100000 01100011 01101111 01110010 01110010 01100101 01100011 01110100 01101100 01111001 00101110 00101110 00101110

In the modern era of information, there's very few people who haven't heard of binary, and most people know that there's exactly ***10 kinds of people:** those who understand, and those who don't!* If you didn't get the joke, or even if you did, that's okay. So, let me start off with a question: if you needed to send a secret message to your neighbor in the middle of the night, and all you have are the light switches in your rooms, how would you convey your messages? You'd probably consider the light to be your *signal* and come up with a set of *codes* which create your *language*. For example, On-off-on might mean, "hey, where's my cat", and off-off-on might mean "I don't know", but on-on-off might mean "in my house", and on-on-on might mean "in my house. Please come get your cat, I'm all out of boxes." In modern electronics, at least in the simple devices we'll be using, electricity is our signal. Just like your bedroom lights, there's two *states* that a DC electrical signal can have: "on" and "off" (these are sometimes described as "logic high" and "logic low"). Put simply, On is 1, and Off is 0, so the codes described above would be:
* 101: "Hey, where's my cat?"
* 001: "I don't know."
* 110: "In my house."
* 111: "In my house. Please come get your cat, I'm all out of boxes."

_**...and that's basically it**_

#### But wait, there's more!

So, obviously, 1 and 0 are numbers, and when you have numbers, that means we can count right?

Yes, the primary purpose of Binary is actually to represent a number value:
* 101<sub>2</sub> 5<sub>10</sub> 
* 001<sub>2</sub> 1<sub>10</sub> 
* 110<sub>2</sub> 6<sub>10</sub> 
* 111<sub>2</sub> 7<sub>10</sub>

Okay, that's fancy, what's whith the weird subscripts? The subscripts mean that the number **X<sub>n</sub>** is the value **X** displayed in "base n", confusing right? So, let's go back to normal **decimal** numbers, "deci" meaning "ten", is a *base ten* number system. That means that there's ten unique characters that are *indexed* (meaning listed, in-order) as 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9, and when you get to 9, you rotate the first *digit* back to 0 and *carry* a 1 into the "tens" place. Again, after you count up to 99 you roll both digits back to 0, and carry a 1 into the hundreds place. This continues into thousands, tens of thousands, hundreds of thousands, and so on. In fact, each of these new "digits" is represented by 10 to the power of n, with n being the position away from the "ones" digit.

So, to get a number abcd<sub>10</sub>, we would add 
d x 1 + c x 10 + b x 100 a x 1000

***Or if you wanted to get really mathy (that's "fancy and math", a 10 for 01 special):***
abcd<sub>10</sub> = d x 10<sup>0</sup> + c x 10<sup>1</sup> + b x 10<sup>2</sup> + a x 10<sup>3</sup>
*Remember: any nonzero number to the power of 0 is equal to 1.*

Let's try this out:
4263<sub>10</sub> = 
3 x 10<sup>0</sup> =    3  
6 x 10<sup>1</sup> =   60  
2 x 10<sup>2</sup> =  200 
4 x 10<sup>3</sup> = 4000 
-------------------------
                     4263


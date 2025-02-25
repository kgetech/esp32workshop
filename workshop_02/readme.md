## Workshop 2: Getting Down Two the Basics!
### One: Okay, so what exactly are Embedded Systems? 

Well, we can break the topic down in a number of ways, but I like how the team at [geeksforgeeks.org](https://www.geeksforgeeks.org/introduction-of-embedded-systems-set-1/) breaks the topic down into two parts:
> [A system] is a set of interrelated parts/components which are designed/developed to perform common tasks or to do some specific work for which it has been created.

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

|4263<sub>10</sub>: | | 
|-------------------:|--:|
|3 x 10<sup>0</sup>|    3  |
|6 x 10<sup>1</sup>|   60  |
|2 x 10<sup>2</sup>|  200 |
|4 x 10<sup>3</sup>| 4000    |
|                  =|  4263<sub>10</sub>|

It may seem really silly, but this is also how ***binary**** numbers work:

|1011<sub>2</sub>:  | |
|-------------------:|--:|
|1 x 2<sup>0</sup>|    1<sub>10</sub>|
|1 x 2<sup>1</sup>|    2<sub>10</sub> |
|0 x 2<sup>2</sup>|    0<sub>10</sub>|
|1 x 2<sup>3</sup>|    8<sub>10</sub>|
|                    =  |11<sub>10</sub>|

...and the inverse is also true, if you want to find the binary version of a decimal number, you start by ***dividing by two:***
|Divide by 2| Quotient| Remainder [note]|
|-------------------:|:--:|:-:|
|11<sub>10</sub>/2<sub>10</sub> | 5 | 1|
 |5<sub>10</sub>/2<sub>10</sub> | 2 | 1|
 |2<sub>10</sub>/2<sub>10</sub> | 1 | 0|
 |1<sub>10</sub>/2<sub>10</sub> | 0 | 1|
 
...and each of these is called a "bit" instead of a "digit". *Fun fact, 8 bits is a Byte, and 4 bits is lovingly referred to as a "nybble".*
*[note]Recalling your early algebra, the **remainder** is what becomes the decimal or fractional component of your **quotient**--the part that cannot be divided equally by the **divisor**.*
***MIND: BLOWN***

One note here, we can also use a calculator with a "modulo" operator "n%d" or "mod(numerator, denominator)" if you're fancy and like MATLAB/Octave. The modulo operator divides the numerator "n" by the denominator "d" and returns the remainder. 

In plain English: if you divide 11 by 2, you get 5 and 1/2, 1 divided by 2, the 1 is the remainder.

Okay, moving forward from this dead horse, the same applies to everything to the right of the "decimal point" in both base 10 and base 2, but when you go to the right, your exponents become negative.

If anyone ever gives you a binary number like 

|0.1011<sub>2</sub>:|| |
|-------------------:|--:|--:|
|0 x 2<sup>0</sup>  |    0<sub>10</sub>  | 0.0|
|1 x 2<sup>-1</sup> |    (1/2)<sub>10</sub>|0.5|
|1 x 2<sup>-2</sup> |    (1/4)<sub>10</sub> |0.25|
|0 x 2<sup>-3</sup> |    0<sub>10</sub>|0.0|
|1 x 2<sup>-4</sup> |    (1/16)<sub>10</sub>|0.0625|
| | | 0.8125<sub>10</sub>|

Of course, speaking of ***Negative Numbers*** binary also has a feature for this.

In any given integer (meaning, any number that is not fractional), you can have a signed or unsigned value.

A ***signed*** integer can be positive or negative.
An ***unsigned*** integer can only be positive.

Why does this matter? Well, in the microcontroller's architecture, we typically talk about memory units called ***words***. A "word" is the maximum size a memory position can take. It's a quite fascinating topic, if you're interested in studying memory and computational architecture--but consider it to be the great bottleneck. There are no roads that can carry numbers larger than the system's word size. If a word is defined as 8 bits, it is considered an 8 bit system, and the largest space in memory, and the largest number the microcontroller's ALU (arithmetic logic unit) can handle is 8 bits. If you have numbers larger than 8 bits, they need to be handled by special software or hardware operations--but enough geeking out, it's the bottleneck. 

So, why signed and unsigned, why not just use signed for everything? Well, if you can only fit 8 bits into memory, and one of those bits marks the sign (positive or negative), then you only have 7 bits left to describe the numeric value. That cuts the size of the number you can describe ***in half***. 

So, what's the biggest number you can store in 8 bits anyway? Well, we could go an add up each 2<sup>n</n> position, but the easiest way is to take ***2<sup>n</sup> - 1***. So,  if 2<sup>8</sup> is 256, then the maximum value that an 8 bit number can carry is 255--and that is useful for a lot of things, but 2<sup>7</sup> is only 128, meaning a signed 8 bit number can only carry values from -128 to 127 (-128, because negative numbers are typically represented in reverse order, starting with the lowest value at 10000000 ascending to 11111111 (-1<sub>10</sub>), before rolling back to 0, because 0 does not need to be included twice, as -0 is equal to + 0. 

#### Let's talk logic!

***Now that you're fully confused:*** We can count numbers, and trust that we can add, subtract, divide, multiply (and these are all built on binary addition, but that's a topic for a different workshop), furthermore, trust that software can work with larger numbers than those limited to a system's word size. *By the way, the ESP32 has a word size of, **you guessed it!** 32 bits, also known as 4 Bytes.*

So, what is logic? Well, if you've ever taken a class in logic and debate, you know that logic is constructed of *arguments*. The purpose of arguments? To prove that a *statement* is ***true*** or ***false***. In most programming languages, true is assigned the value of 1, and false is assigned the value of 0 or NULL. However, at the hardware level, this may not be the case. *For example, in some protocols, a logic level high may be considered false, null, and 0.* For now let's assume that 0 is logic level low, null, and false, and that 1 is logic level high, true. 

***This is about to go pretty deep, but it is important for you to understand in order to work with binary systems.*** 

Let's use a word size of 4 bits, and to keep life simple, I will utilize a notation common to C and C++: 0bNNNN represents a binary number, and NN represents a decimal number. There's also 0xN which is hexadecimal: base 16, but we won't cover this just yet (but know that the principle is still the same, it's just finicky). *Try to guess why I used less digits to describe a four bit number, and less positions to describe a 16-bit number.*

##### Logic Operators

In computing, a lot of things do stuff, the way that we describe these interactions is by way of *operators*. An operator performs an *operation* on an *operand* or *operands*, producing a *result*. 

You're probably familiar with a lot of operators already!

| Operator| Operation          |
|--------:|:-------------------|
|+        | r = a plus b       |
|-        | r = a minus b      |
|*        | r = a times b      |
|/        | r = a divided by b |

These are all *arithmetic* operators, they do math, it works--***cool!***

Similarly, there are logical operators we'll be using those specified in the [Arduino Reference Documentation](https://docs.arduino.cc/language-reference/#structure):

| Operator| Operation          |
|--------:|:-------------------|
|~       | bitwise NOT     |
|&        | bitwise AND      |
|\|        | bitwise OR      |
|^        | bitwise XOR |

There are several other operators, but for now, we'll focus on these. The term "bitwise" means that the operator is assgned by bit. So, for our 4 bit binary number, a bitwise operator will compare bit 0 of one number with bit 0 of another number, similarly bit 1 with bit 1, and so on to bit n for an n-bit word size. 

###### Bitwise NOT
Also referred to as an "inversion" operator, if `~` is applied to a value of `0b0` the value becomes `0b1`, and similarly, if ~ is applied to `0b1` the value becomes `0b0`. Pretty simple: you're just turning over a coin, heads to tails.

Example:
~0b1011 = 0b0100

###### Bitwise AND
Bitwise AND is a little more complicated, basically AND returns "true" if all input arguments are true. So, in the context of bitwise AND and two four bit numbers, bit 0 output = 1 only if bit 0 of input 1 and bit 0 of input 2 is equal to 1.

|A|B|Y = A & B|
|-|-|:-|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

Sidenote: this is called a "Truth Table" which is a table of all possible inputs and outputs to a logic expression.

Example:
0b1001 & 0b0101 = 0b0001

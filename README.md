# morse-table
Arduino code to trigger morse from text (via K6HX)

I find this code from https://brainwagon.org to be particularly ingenious.

K6HX uses decimal numbers converted to binary with `bitwise AND` operation to trigger dits and dahs in the send function.

While most would have probably created a hardcoded translation table or something with timers, this is a more elegant way: Traverse the binary number as CW characters.

I just had to re-post here with commentary and props to Mark VandeWettering for this code.

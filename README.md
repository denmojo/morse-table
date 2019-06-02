# morse-table
Arduino code to trigger morse from text (via K6HX)

I find this code found on https://brainwagon.org to be particularly ingenious.
K6HX uses decimal numbers converted to binary with bitwise AND operation to trigger dits and dahs in the send function.
While most would have probably created a hardcoded translation table or something with timers, this is an elegant way to traverse binary numbers as CW characters. I just had to re-post here with commentary and props to Mark VandeWettering for this code.

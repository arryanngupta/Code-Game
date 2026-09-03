<h2><a href="https://www.geeksforgeeks.org/problems/distinct-coloring--170645/1">Paint N Houses</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);" bis_skin_checked="1"><p><span style="font-size: 18px;">There are n houses arranged in a row. Each house must be painted using exactly one of three colors: red, green, or blue.<br></span><span style="font-size: 18px;">The cost of painting the i-th house with each color is given by three arrays:</span></p>
<ul>
<li><span style="font-size: 18px;">r[i] — cost of painting house i red</span></li>
<li><span style="font-size: 18px;">g[i] — cost of painting house i green</span></li>
<li><span style="font-size: 18px;">b[i] — cost of painting house i blue</span></li>
</ul>
<p><span style="font-size: 18px;">Paint all the houses such that no two adjacent houses have the same color.<br></span><span style="font-size: 18px;">Return the minimum total cost required to paint all n houses while satisfying this condition.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: r[] = [1, 1, 1], g[] = [2, 2, 2], b[] = [3, 3, 3]
<strong>Output:</strong>&nbsp;4
<strong>Explanation</strong>: For the three houses, the cheapest valid coloring is RGR. The total cost is 1 + 2 + 1 = 4. <br>Although painting all three houses red would have a total cost of 3, <br>this is not allowed because two adjacent houses cannot have the same color.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>r[] = [2, 1, 3], g[] = [3, 2, 1], b[] = [1, 3, 2] 
<strong>Output:</strong>&nbsp;3
<strong>Explanation</strong>: A minimum-cost valid coloring is BRG. The corresponding costs are 1, 1, and 1, giving a total cost of 3. <br>No two adjacent houses have the same color, so the coloring satisfies the required condition.</span></pre>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Walmart</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;
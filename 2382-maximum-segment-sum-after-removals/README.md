<h2><a href="https://leetcode.com/problems/median-of-two-sorted-arrays/">4. Median of Two Sorted Arrays</a></h2>
<h3>Hard</h3>
<hr>
<div><p>You are given two <strong>0-indexed</strong> integer arrays <code>nums</code> and <code>removeQueries</code> , both of length <code>n</code>. For the <code>i<sup>th</sup></code> query, the element in <code>nums</code>  at the index  <code>removeQueries[i]</code> is removed, splitting <code>nums</code> into different segments.</p><p>A <strong>segment</strong> is a contiguous sequence of <strong>positive</strong> integers in <code>nums</code>. A <strong>segment sum</strong> is the sum of every element in a segment.</p><p>Return an integer array <code>answer</code>, of length <code>n</code>, where <code>answer[i]</code> is the <strong>maximum</strong> segment sum after applying the <code>i<sup>th</sup></code> removal.</p><p> <strong>Note:</strong> The same index will <strong>not</strong> be removed more than once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
<strong>Output:</strong> [14,7,2,2,0]
<strong>Explanation:</strong> Using 0 to indicate a removed element, the answer is as follows:
<p>Query 1: Remove the 0th element, nums becomes [0,2,5,6,1] and the maximum segment sum is 14 for segment [2,5,6,1].</p>
<p>Query 2: Remove the 3rd element, nums becomes [0,2,5,0,1] and the maximum segment sum is 7 for segment [2,5].</p>
<p>Query 3: Remove the 2nd element, nums becomes [0,2,0,0,1] and the maximum segment sum is 2 for segment [2].</p> 
<p>Query 4: Remove the 4th element, nums becomes [0,2,0,0,0] and the maximum segment sum is 2 for segment [2].</p> 
<p>Query 5: Remove the 1st element, nums becomes [0,0,0,0,0] and the maximum segment sum is 0, since there are no segments.</p><p>Finally, we return [14,7,2,2,0].</p>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,11,1], removeQueries = [3,2,1,0]
<strong>Output:</strong> [16,5,3,0]
<strong>Explanation:</strong> Using 0 to indicate a removed element, the answer is as follows:
<p>Query 1: Remove the 3rd element, nums becomes [3,2,11,0] and the maximum segment sum is 16 for segment [3,2,11].</p>
<p>Query 2: Remove the 2nd element, nums becomes [3,2,0,0] and the maximum segment sum is 5 for segment [3,2].</p>
<p>Query 3: Remove the 1st element, nums becomes [3,0,0,0] and the maximum segment sum is 3 for segment [3].</p>
<p>Query 4: Remove the 0th element, nums becomes [0,0,0,0] and the maximum segment sum is 0, since there are no segments.</p>
<p>Finally, we return [16,5,3,0].</p>
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length == removeQueries.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= removeQueries[i] &lt; n</code></li>
	<li> All the values of <code>removeQueries</code> are unique.</li>

</ul>
</div>
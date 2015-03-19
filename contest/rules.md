---
layout: default
title: SIG-ICPC Dropbox Open Programming Contest Rules
---

<h1 class="title">Dropbox Open Rules</h1>
<br>

<a name="Logistics"></a>
<h2 class="title">Contest Logistics and Registration:</h2>
The <b>SIG-ICPC Dropbox Open Programming Contest</b>, hereafter referred to as “the Dropbox Open” or “the contest”, will be held on <b>Saturday, April 18th, from 10:30 AM to 6 PM CDT</b>. The contest will take place in <b>Room 2405 of the Thomas M. Siebel Center for Computer Science, located at 201 N. Goodwin Avenue, Urbana, IL 61801</b>. All participants in the contest must register at the contest website, <a class="contest" href="/contest/register.html">http://icpc.cs.illinois.edu/contest/register.html</a>. <b>Registration closes promptly at 10:30 AM CDT on the morning of Saturday, April 18th.</b>

<br>

After the close of registration on the day of the contest, the Dropbox Open contest team will issue contest environment login credentials to each team to be used for the duration of the contest. Before the start of the contest, teams may use the login credentials to participate in a <b>practice contest</b> that will be used to ensure that all participants are familiar with the contest environment. <b>The practice contest will start at 10:30 AM CDT and will end at 11:45 AM CDT. The official SIG-ICPC Dropbox Open Programming Contest will start promptly at 12:00 PM CDT and run for a duration of five (5) hours until 5:00 PM CDT</b>. Following the contest, the judges will perform final scoring and announce the results.

<br>

Snacks and water will be provided during the contest, and dinner will be provided after the contest. Contestants may bring their own food and drinks to the contest if desired.

<br>

Upon participation in the contest, it is implied that we reserve the right to share your resume and other information with our corporate sponsor, Dropbox, and use them for SIG-ICPC recruitment purposes. By attending the SIG-ICPC Dropbox Open Programming Contest, you acknowledge that your picture and video may be used without compensation, prior permission, or notification in any promotional material related to SIG-ICPC or the Dropbox Open.

<br>

<a name="Teams"></a>
<h2 class="title">Teams:</h2>
Participants must compete in <b>teams</b> of their own choosing of <b>three (3) students</b>. All teams must be registered before the start of the contest to participate. Participants who cannot find a team before the date of the contest will be matched to other students on a first-registered first-serve basis on the date of the competition starting immediately after the close of registration. Unlike ICPC contests, we are allowing participants to use their own laptop computers (up to a maximum of three (3) computers per team) and have full access to any physical materials or online resources during the contest, excepting mobile phones. Participants may <b>NOT</b> communicate with anyone during the contest except their team or the contest staff for any matter related to the contest, or risk disqualification at the discretion of the Dropbox Open contest team.

<br>

<a name="Eligibility"></a>
<h2 class="title">Eligibility:</h2>
All participants must be full-time or part-time students at the University of Illinois at Urbana-Champaign during Spring 2015, and must not be graduating prior to December 2015. Participants must plan to be enrolled as either full-time or part-time students in the December 2015 semester. Participants must also meet all 2015 ICPC Regionals eligibility requirements, which are as follows: 1) Participants must not have competed in 2 ICPC World Finals competitions or 5 ICPC Regionals competitions. 2) Participants must have started post-secondary studies in or after 2011, or must have been born in 1992 or later. The full eligibility requirements are indicated in the flowchart available at <a class="contest" href="/contest/eligibility.pdf">http://icpc.cs.illinois.edu/contest/eligibility.pdf</a>. Any participants seeking exemptions to the eligibility requirements must contact the Dropbox Open contest team at <a class="contest" href="mailto:icpc@cs.illinois.edu">icpc@cs.illinois.edu</a>.

<br>

<a name="ContestEnvironment"></a>
<h2 class="title">Contest Environment:</h2>
During the contest, teams will submit proposed solutions to the contest problems to the Judges using the DOMjudge contest control system. Solutions will only be accepted in the C, C++ or Java programming languages. Source files submitted to the Judges will be compiled using the following command line arguments for the respective language:

<p style="margin-left:2em">
C (C99):<br>
<code style="background-color:#dedede;margin-left:2em">gcc -Wall -O2 -static -pipe -std=gnu99 "$*" -lm</code>

<br>

C++ (C++11):<br>
<code style="background-color:#dedede;margin-left:2em">g++ -Wall -O2 -static -pipe -std=gnu++11 "$*"</code>

<br>

Java (Java 7): <br>
<code style="background-color:#dedede;margin-left:2em">javac -d . $*</code>
</p>

<br>

The "$*" in the above commands represents the list of source files from the submission which will actually be compiled. Files with the following suffixes (and only files with these suffixes) will be submitted to the compiler:
<div style="margin-left:2em">
For C submissions: files ending with .c

For C++ submissions: files ending with .cc, .cpp, .cxx, .c++, or .C

For Java submissions: files ending with .java
</div>

<br>

For C/C++, the resulting executable will be executed to generate the output of the submission.  
For Java, the compiled code will be executed using the following command:
<p>
<code style="background-color:#dedede;margin-left:2em">java -Xrs -Xss8m $*</code>
</p>

<br>

All submissions must read input from standard input and write output to standard output (also known as the console). You will never be required to open (other) files.

<br>

For a summary of the DOMjudge system interface and instructions on submission, reference the DOMjudge team manual, available at <a class="contest" href="/contest/team-manual.pdf">http://icpc.cs.illinois.edu/contest/team-manual.pdf</a>.

<br>

<a name="Judging"></a>
<h2 class="title">Judging:</h2>
Solutions to problems submitted for judging are called 'runs'. Each run is judged as accepted or rejected by a judge, and the team is notified of the results.

<br>

Notification of accepted runs may be suspended at an appropriate time to keep the final results secret. A general announcement to that effect will be made during the contest. Notification of rejected runs will continue until the end of the contest.

<br>

A contestant may submit a claim of ambiguity or error in a problem statement by submitting a clarification request to a judge. If the judges agree that an ambiguity or error exists, a clarification will be issued to all contestants.

<br>

While the contest is scheduled for five hours, the Dropbox Open contest team reserves the authority to alter the length of the contest in the event of unforeseen difficulties. Should the contest duration be altered, every attempt will be made to notify contestants in a timely and uniform manner.

<br>

A team may be disqualified by the Dropbox Open contest team for any activity that jeopardizes the contest such as dislodging power cords, unauthorized modification of contest materials, communication with outside parties, or distracting behavior.

<br>

At least twelve problems will be posed. So far as possible, problems will avoid dependence on detailed knowledge of a particular applications area or particular contest language.

<br>

<a name="Scoring"></a>
<h2 class="title">Scoring:</h2>
A problem is considered 'solved' when it is accepted by the judges. The judges are solely responsible for accepting or rejecting submitted runs. In consultation with the judges, the Dropbox Open contest staff will determine the winners of the contest. The contest staff and judges are empowered to adjust for or adjudicate unforeseen events and conditions. Their decisions are final.

<br>

Teams will be ranked according to the most problems solved. For the purposes of awards, teams who solve the same number of problems are ranked by least total time. The total time is the sum of the time consumed for each problem solved. The time consumed for a solved problem is the time elapsed from the beginning of the contest to the submittal of the accepted run plus 20 penalty minutes for every rejected run for that problem regardless of submittal time. There is no time consumed for a problem that is not solved.

<br>

In the event that multiple teams have the same number of problems solved and the same total time, ties will be broken based on the submittal time of the accepted runs for the teams. If the last submittal time for the last solved problem is different, the team with the earliest such time will win the tie. Otherwise, the comparison will continue for the second-to-last solved problem, third-to-last, and so forth until the beginning of the contest. Any additional tie-breaker policies will be announced to participants before the contest begins.

<br>

<a name="Prizes"></a>
<h2 class="title">Prizes:</h2>
All members of the highest scoring team will be awarded prizes worth $100. All members of the second highest scoring team will be awarded prizes worth $50. All members of the third highest scoring team will be awarded prizes worth $25.

<br>

All prize-winning teams will be responsible for working with the SIG-ICPC Dropbox Open Programming Contest team, ACM SIG-ICPC executive committee, and the University of Illinois Computer Science department to arrange for delivery of the prizes.

<br>

<h2 class="title">Other:</h2>
Rules are subject to change at any time. The SIG-ICPC Dropbox Open Programming Contest team reserves the right to change contest rules or disqualify any participant at any time at their discretion.

<br>

Dropbox and the Dropbox logo are trademarks of Dropbox, Inc.

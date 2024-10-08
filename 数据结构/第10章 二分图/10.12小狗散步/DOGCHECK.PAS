const
  eps=1e-7;

function dist(x1,y1,x2,y2:longint):real;
begin
  dist:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;

var
   pos,dog:array[1..100]of record x,y:integer; mark:boolean; end;
   n,m,i,now,ans,x,y,p,tot:integer;

procedure error;
begin
  writeln('Wrong Answer!');
  close(input);
  halt;
end;

function findsight(x,y:integer):integer;
var i:integer;
begin
  for i:=1 to m do
    if (dog[i].x=x) and (dog[i].y=y) then begin
      findsight:=i;
      exit;
    end;
  findsight:=0;
end;

begin
  assign(input,'dog.in');
  reset(input);
  readln(n,m);
  for i:=1 to n do begin
    read(pos[i].x,pos[i].y);
    pos[i].mark:=false;
  end;
  for i:=1 to m do begin
    read(dog[i].x,dog[i].y);
    dog[i].mark:=false;
  end;
  close(input);
  assign(input,'dog.out');
  reset(input);
  read(ans);
  now:=1;
  tot:=1;
  read(x,y);
  while (now<n) do begin
    if (x<>pos[now].x) or (y<>pos[now].y) then error;
    read(x,y);
    inc(tot);
    inc(now);
    if now>n then break;
    if (x<>pos[now].x) or (y<>pos[now].y) then begin
      p:=findsight(x,y);
      if (dist(pos[now-1].x,pos[now-1].y,x,y)+dist(x,y,pos[now].x,pos[now].y)
      >2*dist(pos[now-1].x,pos[now-1].y,pos[now].x,pos[now].y)+eps) then error;
      if (p=0) then error;
      if dog[p].mark then error;
      dog[p].mark:=true;
      read(x,y);
      inc(tot);
    end;
  end;
  if (x<>pos[now].x) or (y<>pos[now].y) then error;
  if tot<>ans then error;
  if now<>n then error;
  close(input);
  writeln('Check passed, ans=',ans);
  assign(input,'dog.sol');
  reset(input);
  readln(ans);
  writeln('Solution =',ans);
  close(input);
end.
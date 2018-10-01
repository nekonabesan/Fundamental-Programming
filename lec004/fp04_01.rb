require 'bigdecimal'
require 'bigdecimal/util'

$vals = []
$stac = []
$list = []
$lstac = []

def e(x)
  begin
    raise "x is Null" if x == nil
    raise "x is Empty" if x == ''
    $vals.push(x); $list.push(x); return $vals
  rescue => e
    return e
  end
end

def add
  begin
    x = $vals.pop; $vals.push($vals.pop + x); return $vals
  rescue => e
    return e
  end
end

def mul
  begin
    x = $vals.pop; $vals.push($vals.pop * x); return $vals
  rescue => e
    return e
  end
end

def clear
  begin
    $stac = $vals; $lstac = $list ; $vals = []; $list = []; return $vals
  rescue => e
    return e
  end
end

=begin
a. 加える代わりに指定した値を引く機能 dec(x)。
=end
def dec
  begin
    x = $vals.pop; $vals.push($vals.pop - x); return $vals
  rescue => e
    return e
  end
end

=begin
b. うっかり間違って reset した時にそれを取り消せる機能 undo(undo の undo はできなくて
もよいが、できるようにしてもよい)。
=end
def undo
  begin
    result = []
    $vals = $stac; $list = $lstac; return $vals
  rescue => e
    return e
  end
end

=begin
c. これまでに加えた (そして引いた) 値の一覧を表示した上で合計を表示する機能 list(reset
はできた方がよい。reset の undo もできるとなおよい)。
=end
def list(n = nil)
  begin
    result = []
    sum = 0
    $list.push(n) if n != nil
    $list.each_with_index{ |e,i| sum += e }
    result.push(sum)
    result.push($list)
    return result
  rescue => e
    e.message
  end
end

=begin
演習 2 「RPN 電卓」の例題をそのまま打ち込んで動かしなさい。動いたら、さらに次の機能を実現
するメソッドを追加しなさい。
=end
=begin
a. 加算と乗算に加えて減算 (sub)、除算 (div)、剰余 (mod) を追加。
=end
def div
  begin
    x = $vals.pop; $vals.push($vals.pop / x); return $vals
  rescue => e
    return e
  end
end

def mod
  begin
    x = $vals.pop; $vals.push($vals.pop % x); return $vals
  rescue => e
    return e
  end
end

=begin
b. 現在の演算結果の符号を反転する操作 inv。たとえば「1 2 add inv → -3」となる。
=end
def inv
  begin
    x = $vals.push($vals.pop * -1); return $vals
  rescue => e
    return e
  end
end

=begin
c. 最後の結果と 1 つ前の結果を交換する操作 exch。たとえば「1 3 exch sub → 2」となる。
=end
def exch
  begin
    x = $vals.pop; y = $vals.pop; $vals.push(x,y)
  rescue => e
    return e
  end
end

=begin
d. ご破産の機能 clear と、開始またはご破産から現在までの操作をすべて横に並べて (つま
り RPN で) 表示する機能 show。6
=end


=begin
e. その他、RPN 電卓にあったらよいと思う任意の機能。
=end

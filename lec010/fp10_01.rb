require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require '../modules/fp_module.rb'

# a. 用の構造体定義
Cell = Struct.new(:data, :next)

=begin
演習 1 ここまでの例 (構築、長さ、プリント) を打ち込んで動かせ。動いたら、次のメソッドを作っ
てみよ (ループでも再帰でも好きな方でよい)。
=end
def atol(a)
  begin
    raise ArgumetError if a.nil?
    p = nil
    (a.length - 1).step(0, -1) do |i|
      p = Cell.new(a[i], p)
    end
    return p
  rescue => e
    return e
  end
end

def atolr(a, pos = 0)
  begin
    raise ArgumetError if a.nil?
    if a.length <= pos
      return nil
    else
      return Cell.new(a[pos], atolr(a, pos + 1))
    end
  rescue => e
    return e
  end
end

=begin
a. data に数値が入っている単連結リストに対して、その数値の合計を求める listsum。
=end
def a(n = 10)
  begin
    raise ArgumetError if n.nil?
    address = Array.new
    result = 0
    for i in 0..n do
      p = Cell.new(i,nil)
      address.push(p)
    end
    p = create(address)
    while true do
      result += p.data
      break if p.next == nil
      p = p.next
    end
    return result
  rescue => e
    return e
  end
end

=begin
配列化された構造体への参照から単連結リストを生成するメソッド
@param Array
@return Constructor(先頭要素へのポインタ)
=end
def create(array)
  begin
    raise ArgumetError if array.nil?
    cnt = array.length - 1
    nxt = nil
    result = nil
    while cnt >= 0 do
      array[cnt].next = nxt
      nxt = array[cnt]
      result = array[cnt]
      cnt -= 1
    end
    return result
  rescue => e
    return e
  end
end

=begin
b. 各セルのdata(文字列)を連結した1つの文字列を返すlistcat。文字列連結は「p.data.to s
+ …」のように to s で文字列にしてから「+」を使えばよい。
=end
def b(str)
  begin
    raise ArgumetError if str.nil?
    s = str.split("")
    t = Array.new
    result = ""
    s.each_with_index do |val,i|
       p = Cell.new(val,nil)
       t.push(p)
    end
    p = create(t)
    while true do
      result += p.data.to_s
      break if p.next == nil
      p = p.next
    end
    return result
  rescue => e
    return e
  end
end

=begin
c. 上と同様だがただし逆順に連結する listcatrev。
=end
def c(str)
  begin
    raise ArgumetError if str.nil?
    s = str.split("")
    t = Array.new
    l = nil
    result = ""
    s.each_with_index do |val,i|
       p = Cell.new(val,nil)
       t.push(p)
    end
    p = create(t)
    while true do
      break if l.nil?
      result += l.data.to_s
      l = l.next
    end
    return l
  rescue => e
    return e
  end
end

=begin
d. printlist と同様だが、1 行目は 1 回、2 行目は 2 回、3 行目は 4 回、…と倍倍で打ち出す
回数が増える printmany。打ち出す順番は任意の順番で (ごちゃまぜで) よい。
=end
def d
  begin
  rescue => e
    return e
  end
end

=begin
e. listsum と同様だが、ただし奇数番目のセルの値だけ合計する listoddsum。
ヒント: ループでも再帰でも「次をたどる」代わりに「次の次をたどる」ようにすれば 1
つおきになります。ただし「次が nil」になることもあるのに注意。再帰では別の方法とし
て、自分自身を再帰呼び出しする代わりに、奇数番目用 (加算をする) は偶数番目用 (加算
しない) を呼び、偶数番目用は奇数番目用を呼ぶ、というふうに交互にやる方法もありま
す。これを相互再帰と呼びます。
=end
def e
  begin
  rescue => e
    return e
  end
end

=begin
f. 単リストの並び順を逆向きにした単リストを返す listrev。これには元のリストを変更し
てしまう版と変更しない版とが考えられるが、どちらでもよいことにする。
=end
def f
  begin
  rescue => e
    return e
  end
end

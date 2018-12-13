require 'benchmark'
require 'bigdecimal'
require 'bigdecimal/util'
require '../modules/fp_module.rb'
#/=============================================================================/
# 演習 1 ここまでの例 (構築、長さ、プリント) を打ち込んで動かせ。
# 動いたら、次のメソッドを作ってみよ (ループでも再帰でも好きな方でよい)。
#/=============================================================================/
# a. 用の構造体定義
Cell = Struct.new(:data, :next)
Cell2 = Struct.new(:data, :next, :prev)

#/=============================================================================/
# a. data に数値が入っている単連結リストに対して、その数値の合計を求める listsum。
#/=============================================================================/
def listsum(n = 10)
  begin
    raise ArgumentError if n.nil?
    address = Array.new
    result = 0
    for i in 0..n do
      p = Cell.new(i,nil)
      address.push(p)
    end
    p = listcat(address)
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

#/=============================================================================/
# b. 各セルのdata(文字列)を連結した1つの文字列を返すlistcat。
#  文字列連結は「p.data.to s+ …」のように to s で文字列にしてから「+」を使えばよい。
#/=============================================================================/
def b(str)
  begin
    raise ArgumentError if str.nil?
    s = str.split("")
    t = Array.new
    result = ""
    s.each_with_index do |val,i|
       p = Cell.new(val,nil)
       t.push(p)
    end
    p = listcat(t)
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

#/=============================================================================/
# c. 上と同様だがただし逆順に連結する listcatrev。
#/=============================================================================/
def listcatrev(str)
  begin
    raise ArgumentError if str.nil?
    s = str.split("")
    t = Array.new
    result = ""
    s.each_with_index do |val,i|
       p = Cell.new(val,nil)
       t.push(p)
    end
    p = listcat(t)
    r = listrev(p)
    while true do
      result += r.data
      break if r.next == nil
      r = r.next
    end
    return result
  rescue => e
    return e
  end
end

#/=============================================================================/
# d. printlist と同様だが、1 行目は 1 回、2 行目は 2 回、3 行目は 4 回、…と倍倍で打ち出す
# 回数が増える printmany。打ち出す順番は任意の順番で (ごちゃまぜで) よい。
#/=============================================================================/
def printmany(str)
  begin
    raise ArgumentError if str.nil?
    s = str.split("")
    t = Array.new
    result = ""
    s.each_with_index do |val,i|
       p = Cell.new(val,nil)
       t.push(p)
    end
    p = listcat(t)
    t.length.times do |i|
      (i + 1).times{ result += p.data.to_s }
      p = p.next
    end
    return result
  rescue => e
    return e
  end
end

#/=============================================================================/
# e. listsum と同様だが、ただし奇数番目のセルの値だけ合計する listoddsum。
#   ヒント: ループでも再帰でも「次をたどる」代わりに「次の次をたどる」ようにすれば 1つおきになります。
#   ただし「次が nil」になることもあるのに注意。再帰では別の方法として、
#   自分自身を再帰呼び出しする代わりに、奇数番目用 (加算をする) は偶数番目用 (加算しない) を呼び、
#   偶数番目用は奇数番目用を呼ぶ、というふうに交互にやる方法もあります。これを相互再帰と呼びます。
#/=============================================================================/
def listoddsum(str)
  begin
    raise ArgumentError if str.nil?
    s = str.split("")
    t = Array.new
    result = ""
    s.each_with_index do |val,i|
       p = Cell.new(val,nil)
       t.push(p)
    end
    p = listcat(t)
    t.length.times do |i|
      result += p.data.to_s if i != 0 && i % 2 != 0
      p = p.next
    end
    return result
  rescue => e
    return e
  end
end

#/=============================================================================/
# 配列化された構造体への参照から単連結リストを生成するメソッド
# param Array
# return Constructor(先頭要素へのポインタ)
#/=============================================================================/
def listcat(array)
  begin
    raise ArgumentError if array.nil?
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

#/=============================================================================/
# f. 単リストの並び順を逆向きにした単リストを返す listrev。
# これには元のリストを変更してしまう版と変更しない版とが考えられるが、どちらでもよいことにする。
#/=============================================================================/
def listrev(p)
  begin
    raise ArgumentError if p.nil?
    a = Array.new
    r = Array.new
    while true do
      a.push(p)
      break if p.next.nil?
      p = p.next
    end
    len = a.length - 1
    while len >= 0 do
      r.push(a[len])
      len -= 1
    end
    return listcat(r)
  rescue => e
    return e
  end
end

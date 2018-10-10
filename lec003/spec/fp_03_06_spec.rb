require __dir__ + "/spec_helper"
require __dir__ + '/../fp03_06.rb'
require __dir__ + '/../../modules/fp_pno.rb'

describe "FpPno" do
  obj = FpPno.new
  context "judgePno" do
    it "judgePno(2)" do
      result = obj.judgePno(2)
      expect(result).to eq true
    end
    it "judgePno(3)" do
      result = obj.judgePno(3)
      expect(result).to eq true
    end
    it "judgePno(4)" do
      result = obj.judgePno(4)
      expect(result).to eq false
    end
    it "judgePno(5)" do
      result = obj.judgePno(5)
      expect(result).to eq true
    end
    it "judgePno(6)" do
      result = obj.judgePno(6)
      expect(result).to eq false
    end
    it "judgePno(7)" do
      result = obj.judgePno(7)
      expect(result).to eq true
    end
  end
  context "judgePno2" do
    it "judgePno2(2)" do
      result = obj.judgePno2(2)
      expect(result).to eq true
    end
    it "judgePno2(3)" do
      result = obj.judgePno2(3)
      expect(result).to eq true
    end
    it "judgePno2(4)" do
      result = obj.judgePno2(4)
      expect(result).to eq false
    end
    it "judgePno2(5)" do
      result = obj.judgePno2(5)
      expect(result).to eq true
    end
    it "judgePno2(6)" do
      result = obj.judgePno2(6)
      expect(result).to eq false
    end
    it "judgePno2(7)" do
      result = obj.judgePno2(7)
      expect(result).to eq true
    end
    it "judgePno2(3432)" do
      result = obj.judgePno2(3432)
      expect(result).to eq false
    end
    it "judgePno2(3433)" do
      result = obj.judgePno2(3433)
      expect(result).to eq true
    end
    it "judgePno2(3434)" do
      result = obj.judgePno2(3434)
      expect(result).to eq false
    end
    it "judgePno2(3435)" do
      result = obj.judgePno2(3435)
      expect(result).to eq false
    end
  end
end
describe "演習6" do
  context "a_0" do
    it "a_0(100)" do
      results = a_1(100)
      expect(results).to eq ([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    end
    it "a_0(1)" do
      results = a_1(1)
      expect(results).to be_a(ArgumentError)
    end
    it "a_0(nil)" do
      results = a_1(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "a_1" do
    it "a_1(100)" do
      results = a_2(100)
      expect(results).to eq ([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    end
    it "a_1(1)" do
      results = a_2(1)
      expect(results).to be_a(ArgumentError)
    end
    it "a_1(nil)" do
      results = a_2(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "a_2" do
    it "a_2(100)" do
      results = a_2(100)
      expect(results).to eq ([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    end
    it "a_2(1)" do
      results = a_2(1)
      expect(results).to be_a(ArgumentError)
    end
    it "a_2(nil)" do
      results = a_2(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "b_1" do
    it "b_1(100)" do
      results = b_1(100)
      expect(results).to match_array([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    end
    it "b_1(1)" do
      results = b_1(1)
      expect(results).to be_a(ArgumentError)
    end
    it "b_1(nil)" do
      results = b_1(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end

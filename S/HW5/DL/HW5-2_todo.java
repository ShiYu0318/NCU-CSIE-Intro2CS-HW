import java.util.Scanner;

// TODO 1: 完成 MainDish 類別
class MainDish {
    // 1. 宣告私有屬性：name (字串), price (整數)
    
    // 2. 建立建構子初始化屬性
    
    // 3. 實作 getName() 與 getPrice() 方法
    
}

// TODO 2: 完成 Beverage 類別
class Beverage {
    // 1. 宣告私有屬性：name (字串), basePrice (整數), isLarge (布林值)
    
    // 2. 建立建構子初始化屬性
    
    // 3. 實作 getName() 方法
    
    // 4. 實作 getPrice() 方法 (若 isLarge 為 true，回傳 basePrice + 20，否則回傳 basePrice)
    
}

// TODO 3: 完成 DeliveryOrder 類別
class DeliveryOrder {
    private String orderId;
    private MainDish dish;
    private Beverage drink;

    // 1. 建立建構子，接收上述三個屬性並完成初始化
    

    // 2. 實作 printReceipt() 方法
    // 規格：算出總金額，並依照題目要求的四行格式印出明細
    public void printReceipt() {
        
    }
}

//不需要修改以下的 main 函式
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String orderId = scanner.next();
        
        String dishName = scanner.next();
        int dishPrice = scanner.nextInt();
        
        String bevName = scanner.next();
        int bevBasePrice = scanner.nextInt();
        boolean isLarge = scanner.nextBoolean();
        
        scanner.close();

        MainDish myDish = new MainDish(dishName, dishPrice);
        Beverage myBeverage = new Beverage(bevName, bevBasePrice, isLarge);
        DeliveryOrder myOrder = new DeliveryOrder(orderId, myDish, myBeverage);

        myOrder.printReceipt();
    }
}
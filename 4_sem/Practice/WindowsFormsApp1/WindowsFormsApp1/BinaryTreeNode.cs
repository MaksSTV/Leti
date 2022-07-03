/*using System;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
namespace Fractal
{
    public enum Side
    {
        left,
        right
    }
    public class BinaryTreeNode<T> where T : IComparable
    {

        public BinaryTreeNode(T data, T dataY)
        {
            Data = data;
            DataY = dataY;
        }
        public T Data { get; set; }
        public T DataY { get; set; }
        public BinaryTreeNode<T> LeftNode { get; set; }
        public BinaryTreeNode<T> RightNode { get; set; }
        public BinaryTreeNode<T> ParentNode { get; set; }
        public Side? NodeSide =>
        ParentNode == null
        ? (Side?)null
        : ParentNode.LeftNode == this
        ? Side.left
       : Side.right;
    }
    public class BinaryTree<T> where T : IComparable
    {
        public BinaryTreeNode<T> RootNode { get; set; }

 public BinaryTreeNode<T> Add(BinaryTreeNode<T> node, BinaryTreeNode<T>
currentNode = null)
        {
            if (RootNode == null)
            {
                node.ParentNode = null;
                return RootNode = node;
            }
            currentNode = currentNode ?? RootNode;
            node.ParentNode = currentNode;
            int result;
            return (result = node.Data.CompareTo(currentNode.Data)) == 0
            ? currentNode
            : result < 0
            ? currentNode.LeftNode == null
            ? (currentNode.LeftNode = node)
           : Add(node, currentNode.LeftNode)
            : currentNode.RightNode == null
            ? (currentNode.RightNode = node)
           : Add(node, currentNode.RightNode);
        }
        public BinaryTreeNode<T> Add(T data, T dataY)
        {
            return Add(new BinaryTreeNode<T>(data, dataY));
        }
        public void Remove(BinaryTreeNode<T> node)
        {
            if (node == null)
            {
                return;
            }
            var currentNodeSide = node.NodeSide;
            if (node.LeftNode == null && node.RightNode == null)
            {
                if (currentNodeSide == Side.left)
                {
                    node.ParentNode.LeftNode = null;
                }
                else
                {
                    node.ParentNode.RightNode = null;
                }
            }
            else if (node.LeftNode == null)
            {
                if (currentNodeSide == Side.left)
                {
                    node.ParentNode.LeftNode = node.RightNode;
                }
                else
                {
                    node.ParentNode.RightNode = node.RightNode;
                }
                node.RightNode.ParentNode = node.ParentNode;
            }
            
 else if (node.RightNode == null)
            {
                if (currentNodeSide == Side.left)
                {
                    node.ParentNode.LeftNode = node.LeftNode;
                }
                else
                {
                    node.ParentNode.RightNode = node.LeftNode;
                }
                node.LeftNode.ParentNode = node.ParentNode;
            }
            else
            {
                switch (currentNodeSide)
                {
                    case Side.left:
                        node.ParentNode.LeftNode = node.RightNode;
                        node.RightNode.ParentNode = node.ParentNode;
                        Add(node.LeftNode, node.RightNode);
                        break;
                    case Side.right:
                        node.ParentNode.RightNode = node.RightNode;
                        node.RightNode.ParentNode = node.ParentNode;
                        Add(node.LeftNode, node.RightNode);
                        break;
                    default:
                        var bufLeft = node.LeftNode;
                        var bufRightLeft = node.RightNode.LeftNode;
                        var bufRightRight = node.RightNode.RightNode;
                        node.Data = node.RightNode.Data;
                        node.RightNode = bufRightRight;
                        node.LeftNode = bufRightLeft;
                        Add(bufLeft, node);
                        break;
                }
            }
        }
        public void Remove(T data)
        {
            var foundNode = FindNode(data);
            Remove(foundNode);
        }
        public BinaryTreeNode<T> FindNode(T data, BinaryTreeNode<T> startWithNode = null)
        {
            startWithNode = startWithNode ?? RootNode;
            int result;
            return (result = data.CompareTo(startWithNode.Data)) == 0
            ? startWithNode
            : result < 0
            ? startWithNode.LeftNode == null
            ? null
           : FindNode(data, startWithNode.LeftNode)
            : startWithNode.RightNode == null
            ? null
           : FindNode(data, startWithNode.RightNode);
        }
        public void PrintTree(PictureBox box)
 {
 Bitmap bitmap = new Bitmap(box.Width, box.Height);
        box.Image = bitmap;
 box.Refresh();
 PrintTree(box, bitmap, RootNode);
    }
    private void PrintTree(PictureBox box, Bitmap bitmap, BinaryTreeNode<T>
   startNode, Side? side = null, int x = 0, int y = 200, int lineSize = 250)
    {
        if (startNode != null)
        {
            Graphics gr = Graphics.FromImage(bitmap);
            gr.TranslateTransform(bitmap.Width / 2, bitmap.Height / 2);
            gr.ScaleTransform(1, 1);
            lineSize /= 2;
            Random random = new Random();
            Pen pen = new Pen(Color.FromArgb(random.Next(255), random.Next(255),
           random.Next(255)))
            {
                Width = 3
            };
            if (startNode.LeftNode != null)
            {
                Point[] point = new Point[2];
                point[0].X = x;
                point[0].Y = y;
                point[1].X = x- lineSize;
                point[1].Y = y - 30;
                gr.DrawLine(pen, point[0], point[1]);
            }
            if (startNode.RightNode != null)
            {
                Point[] point = new Point[2];
                point[0].X = x;
                point[0].Y = y;
                point[1].X = x + lineSize;
                point[1].Y = y - 30;
                gr.DrawLine(pen, point[0], point[1]);
            }
            gr.FillEllipse(Brushes.Black, x - 10, y - 10, 20, 20);
            gr.DrawEllipse(pen, x - 10, y - 10, 20, 20);
            gr.DrawString("" + startNode.Data + "|" + startNode.DataY, new
            Font("Arial", 12), Brushes.Green, x - 8, y - 11);
            box.Image = bitmap;
            Thread.Sleep(80);
            box.Refresh();
            x -= lineSize;
            y -= 30;
            PrintTree(box, bitmap, startNode.LeftNode, Side.left, x, y, lineSize);
            x += lineSize*2;
            PrintTree(box, bitmap, startNode.RightNode, Side.right, x, y, lineSize);
        }
    }
}
}*/

using System;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
namespace WindowsFormsApplication2
{
    public enum Side
    {
        first,
        second,
        third,
        fourth
    }
    public class BinaryTreeNode<T> where T : IComparable
    {
        public BinaryTreeNode(T data, T dataY)
        {
            Data = data;
            DataY = dataY;
        }
        public T Data { get; set; }
        public T DataY { get; set; }
        public BinaryTreeNode<T> firstNode { get; set; }
        public BinaryTreeNode<T> secondNode { get; set; }
        public BinaryTreeNode<T> thirdNode { get; set; }

        public BinaryTreeNode<T> fourthNode { get; set; }
        public BinaryTreeNode<T> ParentNode { get; set; }
        public Side? NodeSide =>
        ParentNode == null
        ? (Side?)null
        : ParentNode.firstNode == this
        ? Side.first
        : Side.second;
    }
    public class BinaryTree<T> where T : IComparable
    {
        public int layer = 0;
        public int count = 0;


        public BinaryTreeNode<T> RootNode { get; set; }
        public void Add(BinaryTreeNode<T> node, BinaryTreeNode<T> currentNode = null)
        {
            if (RootNode == null)
            {
                node.ParentNode = null;
                RootNode = node;
                layer++;
            }
            else
            {
                int tmp = 0;
                currentNode = RootNode;
                for (int i = 0; i < layer; i++)
                {
                    if(i == layer-1)
                    {
                        if (currentNode.firstNode == null)
                            currentNode.firstNode = node;
                        else if (currentNode.secondNode == null)
                            currentNode.secondNode = node;
                        else if (currentNode.thirdNode == null)
                            currentNode.thirdNode = node;
                        else if (currentNode.fourthNode == null)
                            currentNode.fourthNode = node;
                        continue;
                    }

                    tmp = (int)(count/Math.Pow(4, layer-i-1));
                    tmp = tmp % 4;
                    if (tmp == 0)
                        currentNode = currentNode.firstNode;
                    else if (tmp == 1)
                        currentNode = currentNode.secondNode;
                    else if (tmp == 2)
                        currentNode = currentNode.thirdNode;
                    else if (tmp == 3)
                        currentNode = currentNode.fourthNode;

                }

                count++;
                if(count == Math.Pow(4, layer))
                {
                    count=0;
                    layer++;
                }
            }
            


        }
        public void Add(T data, T dataY)
        {
            Add(new BinaryTreeNode<T>(data, dataY));
        }
        public void PrintTree(PictureBox box)
        {
            Bitmap bitmap = new Bitmap(box.Width, box.Height);
            box.Image = bitmap;
            box.Refresh();
            PrintTree(box, bitmap, RootNode);
        }
        private void PrintTree(PictureBox box, Bitmap bitmap, BinaryTreeNode<T>
        startNode, Side? side = null, int x = 0, int y = 0, int lineSize = 400)
        {

            if (startNode != null)
            {
                Graphics gr = Graphics.FromImage(bitmap);
                gr.TranslateTransform(bitmap.Width / 2, bitmap.Height / 2);
                gr.ScaleTransform(1, 1);
                lineSize /= 2;
                Random random = new Random();
                int x1 = 0;
                int x2 = 0;
                int x3 = 0;
                int x4 = 0;
                Pen pen = new Pen(Color.FromArgb(random.Next(255), random.Next(255),
                random.Next(255)))
                {
                    Width = 2
                };
                if (startNode.firstNode != null)
                {
                    Point[] point = new Point[2];
                    point[0].X = x;
                    point[0].Y = y - 100;
                    point[1].X = x - lineSize;
                    point[1].Y = y - 60;
                    x1 = point[1].X;
                    gr.DrawLine(pen, point[0], point[1]);
                }
                if (startNode.secondNode != null)
                {
                    Point[] point = new Point[2];
                    point[0].X = x;
                    point[0].Y = y - 100;
                    point[1].X = x - lineSize/3;
                    point[1].Y = y - 60;
                    x2 = point[1].X;
                    gr.DrawLine(pen, point[0], point[1]);
                }
                if (startNode.thirdNode != null)
                {
                    Point[] point = new Point[2];
                    point[0].X = x;
                    point[0].Y = y - 100;
                    point[1].X = x + lineSize/2;
                    point[1].Y = y - 60;
                    x3 = point[1].X;
                    gr.DrawLine(pen, point[0], point[1]);
                }
                if (startNode.fourthNode != null)
                {
                    Point[] point = new Point[2];
                    point[0].X = x;
                    point[0].Y = y - 100;
                    point[1].X = x + lineSize;
                    point[1].Y = y - 60;
                    x4 = point[1].X;
                    gr.DrawLine(pen, point[0], point[1]);
                }
                gr.DrawString("" + startNode.Data + ";" + startNode.DataY, new
                Font("Arial", 12), Brushes.Black, x - 32, y - 110);
                box.Image = bitmap;
                Thread.Sleep(80);
                box.Refresh();
                y += 40;
                x += lineSize*2;
                PrintTree(box, bitmap, startNode.firstNode, Side.first, x1, y, lineSize);
                PrintTree(box, bitmap, startNode.secondNode, Side.second, x2, y, lineSize);
                PrintTree(box, bitmap, startNode.thirdNode, Side.third, x3, y, lineSize);
                PrintTree(box, bitmap, startNode.fourthNode, Side.fourth, x4, y, lineSize);
            }
        }
    }
}
